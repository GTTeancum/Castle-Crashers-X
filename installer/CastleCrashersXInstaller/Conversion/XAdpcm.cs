// SPDX-License-Identifier: MIT
// Xbox ADPCM encoder: the C# form of tools\xadpcm.cpp (same output bytes).
// Xbox ADPCM is IMA ADPCM in 36-byte blocks per channel: int16 first sample,
// uint8 step index, uint8 reserved, then 64 4-bit codes (low nibble first).
// Codes are chosen with a one-sample lookahead (the code whose
// reconstruction plus the best follow-up code has the smallest squared
// error).
namespace CastleCrashersXInstaller.Conversion;

public static class XAdpcm
{
    static readonly int[] Step = [
        7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
        50, 55, 60, 66, 73, 80, 88, 97, 107, 118, 130, 143, 157, 173, 190, 209, 230,
        253, 279, 307, 337, 371, 408, 449, 494, 544, 598, 658, 724, 796, 876, 963,
        1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024, 3327,
        3660, 4026, 4428, 4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442,
        11487, 12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794,
        32767];
    static readonly int[] IndexAdj = [-1, -1, -1, -1, 2, 4, 6, 8];
    const int SamplesPerBlock = 64;
    public const int BlockBytes = 36;

    static int Clamp16(int v) => v < -32768 ? -32768 : (v > 32767 ? 32767 : v);

    // One nibble decoded from (pred, index); returns the new pair.
    static void Decode(ref int pred, ref int index, int code)
    {
        int step = Step[index];
        int diff = step >> 3;
        if ((code & 4) != 0) diff += step;
        if ((code & 2) != 0) diff += step >> 1;
        if ((code & 1) != 0) diff += step >> 2;
        pred = Clamp16((code & 8) != 0 ? pred - diff : pred + diff);
        index += IndexAdj[code & 7];
        index = index < 0 ? 0 : (index > 88 ? 88 : index);
    }

    static int Encode(ref int pred, ref int index, int target, int next)
    {
        int best = 0;
        long bestErr = -1;
        for (int code = 0; code < 16; ++code)
        {
            int tp = pred, ti = index;
            Decode(ref tp, ref ti, code);
            long e1 = tp - target;
            long e2best = -1;
            for (int c2 = 0; c2 < 16; ++c2)
            {
                int up = tp, ui = ti;
                Decode(ref up, ref ui, c2);
                long e2 = up - next;
                if (e2best < 0 || e2 * e2 < e2best) e2best = e2 * e2;
            }
            long err = e1 * e1 + e2best;
            if (bestErr < 0 || err < bestErr) { bestErr = err; best = code; }
        }
        Decode(ref pred, ref index, best);
        return best;
    }

    // Interleaved s16 PCM (frames x channels) to channel-interleaved blocks.
    public static byte[] EncodePcm(short[] pcm, int channels)
    {
        long frames = pcm.Length / channels;
        long blocks = (frames + SamplesPerBlock - 1) / SamplesPerBlock;
        var output = new byte[blocks * BlockBytes * channels];
        int Sample(long frame, int c) => frame >= frames ? 0 : pcm[frame * channels + c];
        var pred = new int[channels];
        var index = new int[channels];
        for (long b = 0; b < blocks; ++b)
            for (int c = 0; c < channels; ++c)
            {
                long o = (b * channels + c) * BlockBytes;
                long first = b * SamplesPerBlock;
                pred[c] = Sample(first, c);
                output[o] = (byte)pred[c]; output[o + 1] = (byte)(pred[c] >> 8);
                output[o + 2] = (byte)index[c]; output[o + 3] = 0;
                for (int i = 0; i < SamplesPerBlock; i += 2)
                {
                    int lo = Encode(ref pred[c], ref index[c], Sample(first + 1 + i, c), Sample(first + 2 + i, c));
                    int hi = Encode(ref pred[c], ref index[c], Sample(first + 2 + i, c), Sample(first + 3 + i, c));
                    output[o + 4 + i / 2] = (byte)(lo | hi << 4);
                }
            }
        return output;
    }
}
