#include <benchmark/benchmark.h>
#include "blake2.h"
int crypto_hash( unsigned char *out, const unsigned char *in, unsigned long long inlen );


// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
    uint8_t buf[4096];
    size_t n=4096;
    uint8_t hash[BLAKE2B_OUTBYTES];
    for (auto _ : state)
        crypto_hash( hash, buf, n );

}
BENCHMARK(BM_StringCopy);
BENCHMARK(BM_StringCopy);
BENCHMARK(BM_StringCopy);

BENCHMARK_MAIN();
