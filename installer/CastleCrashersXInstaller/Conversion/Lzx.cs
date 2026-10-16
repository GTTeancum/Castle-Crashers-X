// SPDX-License-Identifier: MIT
//
// Self-contained LZX decoder: a faithful C# port of the algorithm in libmspack's
// lzxd.c (Stuart Caie). Supports window sizes 32 KB..2 MB, verbatim, aligned
// and uncompressed blocks, Intel E8 call translation (enabled by the stream
// header, as in libmspack) and optional reset intervals. Output is produced in
// 32 KB frames; the input bitstream is re-aligned to 16 bits after every frame.

using System;
using System.IO;

namespace CastleCrashersXInstaller.Conversion;

public sealed class LzxDecoder
{
    // --- LZX constants (lzx.h) ---
    private const int MinMatch = 2;
    private const int MaxMatch = 257;
    private const int NumChars = 256;
    private const int BlockTypeInvalid = 0;
    private const int BlockTypeVerbatim = 1;
    private const int BlockTypeAligned = 2;
    private const int BlockTypeUncompressed = 3;
    private const int PretreeNumElements = 20;
    private const int AlignedNumElements = 8;
    private const int NumPrimaryLengths = 7;
    private const int NumSecondaryLengths = 249;
    private const int FrameSize = 32768;

    // Huffman table geometry (lzxd.c).
    private const int PretreeMaxSymbols = PretreeNumElements;
    private const int PretreeTableBits = 6;
    private const int MainTreeMaxSymbols = NumChars + 50 * 8;
    private const int MainTreeTableBits = 12;
    private const int LengthMaxSymbols = NumSecondaryLengths + 1;
    private const int LengthTableBits = 12;
    private const int AlignedMaxSymbols = AlignedNumElements;
    private const int AlignedTableBits = 7;
    private const int LenTableSafety = 64;
    private const int HuffMaxBits = 16;

    // Number of position slots for window bits 15..21.
    private static readonly int[] PositionSlots = { 30, 32, 34, 36, 38, 42, 50 };

    private static readonly byte[] ExtraBits =
    {
        0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14,
        15, 15, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17,
    };

    private static readonly uint[] PositionBase = BuildPositionBase();

    private static uint[] BuildPositionBase()
    {
        var b = new uint[ExtraBits.Length];
        for (int i = 1; i < b.Length; i++) b[i] = b[i - 1] + (1u << ExtraBits[i - 1]);
        return b;
    }

    // --- Decoder state ---
    private readonly byte[] _window;
    private readonly int _windowSize;
    private readonly int _numOffsets;
    private readonly int _resetInterval; // in frames; 0 = never reset

    private uint _r0, _r1, _r2;
    private bool _headerRead;
    private int _blockType;
    private int _blockLength;
    private int _blockRemaining;
    private int _intelFileSize;
    private bool _intelStarted;
    private bool _lengthEmpty;

    private readonly byte[] _pretreeLen = new byte[PretreeMaxSymbols + LenTableSafety];
    private readonly ushort[] _pretreeTable = new ushort[(1 << PretreeTableBits) + PretreeMaxSymbols * 2];
    private readonly byte[] _mainTreeLen = new byte[MainTreeMaxSymbols + LenTableSafety];
    private readonly ushort[] _mainTreeTable = new ushort[(1 << MainTreeTableBits) + MainTreeMaxSymbols * 2];
    private readonly byte[] _lengthLen = new byte[LengthMaxSymbols + LenTableSafety];
    private readonly ushort[] _lengthTable = new ushort[(1 << LengthTableBits) + LengthMaxSymbols * 2];
    private readonly byte[] _alignedLen = new byte[AlignedMaxSymbols + LenTableSafety];
    private readonly ushort[] _alignedTable = new ushort[(1 << AlignedTableBits) + AlignedMaxSymbols * 2];

    // --- Bit reader (MSB-first over 16-bit little-endian words, readbits.h) ---
    private byte[] _input = Array.Empty<byte>();
    private int _inPos;
    private bool _inputEnd;
    private uint _bitBuffer;
    private int _bitsLeft;

    /// <param name="windowBits">log2 of the window size, 15..21 (32 KB..2 MB).</param>
    /// <param name="resetIntervalFrames">Reset decoder state every N 32 KB frames; 0 = never.</param>
    public LzxDecoder(int windowBits, int resetIntervalFrames = 0)
    {
        if (windowBits < 15 || windowBits > 21)
            throw new InvalidDataException($"Unsupported LZX window: 2^{windowBits} bytes (need 2^15..2^21)");
        if (resetIntervalFrames < 0) throw new ArgumentOutOfRangeException(nameof(resetIntervalFrames));
        _windowSize = 1 << windowBits;
        _window = new byte[_windowSize];
        _numOffsets = PositionSlots[windowBits - 15] << 3;
        _resetInterval = resetIntervalFrames;
    }

    private void ResetState()
    {
        _r0 = _r1 = _r2 = 1;
        _headerRead = false;
        _blockRemaining = 0;
        _blockType = BlockTypeInvalid;
        Array.Clear(_mainTreeLen);
        Array.Clear(_lengthLen);
    }

    /// <summary>Decode one continuous LZX stream into exactly <paramref name="outputLength"/> bytes.</summary>
    public byte[] Decompress(byte[] input, int outputLength)
    {
        if (outputLength < 0) throw new ArgumentOutOfRangeException(nameof(outputLength));
        _input = input;
        _inPos = 0;
        _inputEnd = false;
        _bitBuffer = 0;
        _bitsLeft = 0;
        _intelStarted = false;
        _lengthEmpty = false;
        Array.Clear(_window);
        ResetState();

        var output = new byte[outputLength];
        int outOffset = 0;      // bytes already written (libmspack lzx->offset)
        int windowPosn = 0;
        int framePosn = 0;
        int frame = 0;
        int endFrame = (outputLength + FrameSize - 1) / FrameSize;
        var e8Buf = new byte[FrameSize];

        while (frame < endFrame)
        {
            // Reset interval reached?
            if (_resetInterval != 0 && frame % _resetInterval == 0)
            {
                if (_blockRemaining != 0) throw Bad($"{_blockRemaining} bytes remaining at reset interval");
                ResetState();
            }

            // Stream header: one bit, then optional 32-bit Intel E8 file size.
            if (!_headerRead)
            {
                uint i = ReadBits(1), j = 0;
                if (i != 0) { i = ReadBits(16); j = ReadBits(16); }
                _intelFileSize = (int)((i << 16) | j);
                _headerRead = true;
            }

            int frameSize = FrameSize;
            if (outputLength - outOffset < frameSize) frameSize = outputLength - outOffset;

            // Decode until one more frame is available.
            int bytesTodo = framePosn + frameSize - windowPosn;
            while (bytesTodo > 0)
            {
                if (_blockRemaining == 0) ReadBlockHeader();

                int thisRun = Math.Min(_blockRemaining, bytesTodo);
                bytesTodo -= thisRun;
                _blockRemaining -= thisRun;

                switch (_blockType)
                {
                    case BlockTypeVerbatim:
                    case BlockTypeAligned:
                        thisRun = DecodeCompressedRun(thisRun, ref windowPosn, outOffset);
                        break;
                    case BlockTypeUncompressed:
                        // A run never crosses a frame, so it never wraps the window.
                        for (int k = 0; k < thisRun; k++) _window[windowPosn++] = ReadRawByte();
                        thisRun = 0;
                        break;
                    default:
                        throw Bad("bad block type");
                }

                // A negative run means the last match overran into the next block's share.
                if (thisRun < 0)
                {
                    if (-thisRun > _blockRemaining) throw Bad($"overrun went past end of block by {-thisRun - _blockRemaining}");
                    _blockRemaining -= -thisRun;
                }
            }

            // Streams don't extend over frame boundaries.
            if (windowPosn - framePosn != frameSize)
                throw Bad($"decode beyond output frame limits ({windowPosn - framePosn} != {frameSize})");

            // Re-align input bitstream to 16 bits.
            if (_bitsLeft > 0) EnsureBits(16);
            if ((_bitsLeft & 15) != 0) RemoveBits(_bitsLeft & 15);

            // Intel E8 call translation, then emit the frame.
            if (_intelStarted && _intelFileSize != 0 && frame < 32768 && frameSize > 10)
            {
                Buffer.BlockCopy(_window, framePosn, e8Buf, 0, frameSize);
                UndoE8(e8Buf, frameSize, outOffset, _intelFileSize);
                Buffer.BlockCopy(e8Buf, 0, output, outOffset, frameSize);
            }
            else
            {
                Buffer.BlockCopy(_window, framePosn, output, outOffset, frameSize);
            }

            outOffset += frameSize;
            framePosn += frameSize;
            frame++;
            if (windowPosn > _windowSize) throw Bad("window position beyond window size");
            if (windowPosn == _windowSize) windowPosn = 0;
            if (framePosn == _windowSize) framePosn = 0;
        }

        return output;
    }

    private void ReadBlockHeader()
    {
        // Uncompressed blocks of odd length are followed by a pad byte.
        if (_blockType == BlockTypeUncompressed && (_blockLength & 1) != 0) ReadRawByte();

        _blockType = (int)ReadBits(3);
        uint hi = ReadBits(16), lo = ReadBits(8);
        _blockRemaining = _blockLength = (int)((hi << 8) | lo);

        switch (_blockType)
        {
            case BlockTypeAligned:
                for (int i = 0; i < 8; i++) _alignedLen[i] = (byte)ReadBits(3);
                BuildTable(AlignedMaxSymbols, AlignedTableBits, _alignedLen, _alignedTable, "ALIGNED");
                goto case BlockTypeVerbatim; // rest of the header is the same as verbatim

            case BlockTypeVerbatim:
                ReadLengths(_mainTreeLen, 0, NumChars);
                ReadLengths(_mainTreeLen, NumChars, NumChars + _numOffsets);
                BuildTable(MainTreeMaxSymbols, MainTreeTableBits, _mainTreeLen, _mainTreeTable, "MAINTREE");
                // If literal 0xE8 can appear in this block, E8 translation may be needed.
                if (_mainTreeLen[0xE8] != 0) _intelStarted = true;
                ReadLengths(_lengthLen, 0, NumSecondaryLengths);
                _lengthEmpty = !TryBuildTable(LengthMaxSymbols, LengthTableBits, _lengthLen, _lengthTable);
                if (_lengthEmpty)
                {
                    for (int i = 0; i < LengthMaxSymbols; i++)
                        if (_lengthLen[i] != 0) throw Bad("failed to build LENGTH table");
                }
                break;

            case BlockTypeUncompressed:
                _intelStarted = true; // because we can't assume otherwise
                // Read 1-16 (not 0-15) bits to align to bytes.
                if (_bitsLeft == 0) EnsureBits(16);
                _bitsLeft = 0;
                _bitBuffer = 0;
                _r0 = ReadRawUInt32();
                _r1 = ReadRawUInt32();
                _r2 = ReadRawUInt32();
                break;

            default:
                throw Bad($"bad block type {_blockType}");
        }
    }

    /// <summary>Decode a verbatim/aligned run; returns the remaining run (negative on overrun).</summary>
    private int DecodeCompressedRun(int thisRun, ref int windowPosn, int outOffset)
    {
        bool aligned = _blockType == BlockTypeAligned;
        byte[] window = _window;

        while (thisRun > 0)
        {
            int mainElement = ReadHuffSym(_mainTreeTable, _mainTreeLen, MainTreeMaxSymbols, MainTreeTableBits);
            if (mainElement < NumChars)
            {
                window[windowPosn++] = (byte)mainElement;
                thisRun--;
                continue;
            }

            // Match: length header in the low 3 bits, position slot above.
            mainElement -= NumChars;
            int matchLength = mainElement & NumPrimaryLengths;
            if (matchLength == NumPrimaryLengths)
            {
                if (_lengthEmpty) throw Bad("LENGTH symbol needed but tree is empty");
                matchLength += ReadHuffSym(_lengthTable, _lengthLen, LengthMaxSymbols, LengthTableBits);
            }
            matchLength += MinMatch;

            uint matchOffset;
            int slot = mainElement >> 3;
            switch (slot)
            {
                case 0: matchOffset = _r0; break;
                case 1: matchOffset = _r1; _r1 = _r0; _r0 = matchOffset; break;
                case 2: matchOffset = _r2; _r2 = _r0; _r0 = matchOffset; break;
                default:
                {
                    int extra = slot >= 36 ? 17 : ExtraBits[slot];
                    matchOffset = PositionBase[slot] - 2;
                    if (!aligned)
                    {
                        matchOffset += ReadBits(extra);
                    }
                    else if (extra > 3)
                    {
                        // Verbatim high bits plus an aligned-tree low 3 bits.
                        matchOffset += ReadBits(extra - 3) << 3;
                        matchOffset += (uint)ReadHuffSym(_alignedTable, _alignedLen, AlignedMaxSymbols, AlignedTableBits);
                    }
                    else if (extra == 3)
                    {
                        matchOffset += (uint)ReadHuffSym(_alignedTable, _alignedLen, AlignedMaxSymbols, AlignedTableBits);
                    }
                    else if (extra > 0)
                    {
                        matchOffset += ReadBits(extra);
                    }
                    else
                    {
                        matchOffset = 1; // not defined by the LZX spec; matches libmspack
                    }
                    _r2 = _r1; _r1 = _r0; _r0 = matchOffset;
                    break;
                }
            }

            if (windowPosn + matchLength > _windowSize) throw Bad("match ran over window wrap");

            // Copy the match (byte by byte: source and destination may overlap).
            int dest = windowPosn;
            int len = matchLength;
            if (matchOffset > (uint)windowPosn)
            {
                // Source wraps around the end of the window.
                if (matchOffset > (uint)outOffset && (matchOffset - (uint)windowPosn) > 0)
                    throw Bad("match offset beyond LZX stream");
                long j = (long)matchOffset - windowPosn;
                if (j > _windowSize) throw Bad("match offset beyond window boundaries");
                int src = _windowSize - (int)j;
                if (j < len)
                {
                    len -= (int)j;
                    while (j-- > 0) window[dest++] = window[src++];
                    src = 0;
                }
                while (len-- > 0) window[dest++] = window[src++];
            }
            else
            {
                int src = dest - (int)matchOffset;
                while (len-- > 0) window[dest++] = window[src++];
            }

            thisRun -= matchLength;
            windowPosn += matchLength;
        }
        return thisRun;
    }

    /// <summary>Read the pretree, then use it to delta-decode lens[first..last).</summary>
    private void ReadLengths(byte[] lens, int first, int last)
    {
        for (int i = 0; i < PretreeNumElements; i++) _pretreeLen[i] = (byte)ReadBits(4);
        BuildTable(PretreeMaxSymbols, PretreeTableBits, _pretreeLen, _pretreeTable, "PRETREE");

        int x = first;
        while (x < last)
        {
            int z = ReadHuffSym(_pretreeTable, _pretreeLen, PretreeMaxSymbols, PretreeTableBits);
            if (z == 17)
            {
                int y = (int)ReadBits(4) + 4;
                while (y-- > 0) SetLen(lens, x++, 0);
            }
            else if (z == 18)
            {
                int y = (int)ReadBits(5) + 20;
                while (y-- > 0) SetLen(lens, x++, 0);
            }
            else if (z == 19)
            {
                int y = (int)ReadBits(1) + 4;
                z = ReadHuffSym(_pretreeTable, _pretreeLen, PretreeMaxSymbols, PretreeTableBits);
                z = lens[x] - z;
                if (z < 0) z += 17;
                while (y-- > 0) SetLen(lens, x++, z);
            }
            else
            {
                z = lens[x] - z;
                if (z < 0) z += 17;
                SetLen(lens, x++, z);
            }
        }
    }

    private static void SetLen(byte[] lens, int index, int value)
    {
        // libmspack relies on LENTABLE_SAFETY slack here; we check explicitly.
        if ((uint)index >= (uint)lens.Length) throw Bad("code length run overflows table");
        lens[index] = (byte)value;
    }

    private static void BuildTable(int nsyms, int nbits, byte[] length, ushort[] table, string name)
    {
        if (!TryBuildTable(nsyms, nbits, length, table)) throw Bad($"failed to build {name} table");
    }

    /// <summary>
    /// Canonical Huffman decode table (readhuff.h make_decode_table): direct lookup for
    /// codes up to nbits long, binary tree nodes (indices >= nsyms) for longer codes.
    /// </summary>
    private static bool TryBuildTable(int nsyms, int nbits, byte[] length, ushort[] table)
    {
        uint pos = 0;
        uint tableMask = 1u << nbits;
        uint bitMask = tableMask >> 1;

        // Codes short enough for direct mapping.
        for (int bitNum = 1; bitNum <= nbits; bitNum++)
        {
            for (int sym = 0; sym < nsyms; sym++)
            {
                if (length[sym] != bitNum) continue;
                uint leaf = pos;
                if ((pos += bitMask) > tableMask) return false; // table overrun
                for (uint fill = bitMask; fill-- > 0;) table[leaf++] = (ushort)sym;
            }
            bitMask >>= 1;
        }

        if (pos == tableMask) return true;

        // Mark remaining entries unused.
        for (uint sym = pos; sym < tableMask; sym++) table[sym] = 0xFFFF;

        // Allocation base for tree nodes of long codes.
        uint nextSymbol = (tableMask >> 1) < (uint)nsyms ? (uint)nsyms : (tableMask >> 1);

        // Allow codes to grow up to 16 more bits.
        pos <<= 16;
        tableMask <<= 16;
        bitMask = 1u << 15;

        for (int bitNum = nbits + 1; bitNum <= HuffMaxBits; bitNum++)
        {
            for (int sym = 0; sym < nsyms; sym++)
            {
                if (length[sym] != bitNum) continue;
                if (pos >= tableMask) return false;
                uint leaf = pos >> 16;
                for (int fill = 0; fill < bitNum - nbits; fill++)
                {
                    if (table[leaf] == 0xFFFF)
                    {
                        if ((nextSymbol << 1) + 1 >= (uint)table.Length) return false;
                        table[nextSymbol << 1] = 0xFFFF;
                        table[(nextSymbol << 1) + 1] = 0xFFFF;
                        table[leaf] = (ushort)nextSymbol++;
                    }
                    leaf = (uint)table[leaf] << 1;
                    if (((pos >> (15 - fill)) & 1) != 0) leaf++;
                }
                table[leaf] = (ushort)sym;
                pos += bitMask;
            }
            bitMask >>= 1;
        }
        return pos == tableMask;
    }

    // --- Bitstream primitives ---

    private int ReadHuffSym(ushort[] table, byte[] lens, int nsyms, int tableBits)
    {
        EnsureBits(HuffMaxBits);
        int sym = table[_bitBuffer >> (32 - tableBits)];
        if (sym >= nsyms)
        {
            uint i = 1u << (32 - tableBits);
            do
            {
                if (sym == 0xFFFF || (i >>= 1) == 0) throw Bad("bad Huffman code");
                sym = table[(sym << 1) | ((_bitBuffer & i) != 0 ? 1 : 0)];
            } while (sym >= nsyms);
        }
        RemoveBits(lens[sym]);
        return sym;
    }

    private void EnsureBits(int n)
    {
        while (_bitsLeft < n)
        {
            int b0 = NextInputByte();
            int b1 = NextInputByte();
            _bitBuffer |= (uint)((b1 << 8) | b0) << (16 - _bitsLeft);
            _bitsLeft += 16;
        }
    }

    private uint ReadBits(int n)
    {
        if (n == 0) return 0;
        EnsureBits(n);
        uint v = _bitBuffer >> (32 - n);
        RemoveBits(n);
        return v;
    }

    private void RemoveBits(int n)
    {
        _bitBuffer = n >= 32 ? 0 : _bitBuffer << n;
        _bitsLeft -= n;
    }

    private byte ReadRawByte() => (byte)NextInputByte();

    private uint ReadRawUInt32()
    {
        uint b0 = ReadRawByte(), b1 = ReadRawByte(), b2 = ReadRawByte(), b3 = ReadRawByte();
        return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
    }

    // Like libmspack's read_input: past the end, supply two zero bytes once, then fail.
    private int _padBytes;
    private int NextInputByte()
    {
        if (_inPos < _input.Length) return _input[_inPos++];
        if (!_inputEnd) { _inputEnd = true; _padBytes = 2; }
        if (_padBytes-- > 0) return 0;
        throw Bad("input data ended prematurely");
    }

    /// <summary>Undo Intel E8 call translation on one frame (curpos = frame's output offset).</summary>
    private static void UndoE8(byte[] data, int frameSize, int curpos, int fileSize)
    {
        int p = 0, end = frameSize - 10;
        while (p < end)
        {
            if (data[p++] != 0xE8) { curpos++; continue; }
            int absOff = data[p] | (data[p + 1] << 8) | (data[p + 2] << 16) | (data[p + 3] << 24);
            if (absOff >= -curpos && absOff < fileSize)
            {
                int relOff = absOff >= 0 ? absOff - curpos : absOff + fileSize;
                data[p] = (byte)relOff;
                data[p + 1] = (byte)(relOff >> 8);
                data[p + 2] = (byte)(relOff >> 16);
                data[p + 3] = (byte)(relOff >> 24);
            }
            p += 4;
            curpos += 5;
        }
    }

    private static InvalidDataException Bad(string message) => new($"LZX: {message}");
}
