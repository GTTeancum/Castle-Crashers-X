// FNV-32 checks supplement exact byte comparisons; not cryptographic proofs.
#pragma once
#include <stdint.h>
static constexpr uint32_t expected_hashes[3][3]={{0xcba599f9,0x811c9dc5,0xcba599f9},{0x3c3dff7b,0x662e8ebd,0x3c3dff7b},{0x992e2ac3,0x4279c201,0x992e2ac3}};
