
#include "blake2.h"
#include "blake2-kat.h"
#include <string.h>
#include "gtest/gtest.h"

int crypto_hash( unsigned char *out, const unsigned char *in, unsigned long long inlen );


// Tests factorial of 0.
TEST(FactorialTest, Zero) {

  uint8_t buf[KAT_LENGTH];
  size_t i;

  for( i = 0; i < KAT_LENGTH; ++i )
    buf[i] = i;

  for( i = 0; i < KAT_LENGTH; ++i )
  {
    uint8_t hash[BLAKE2B_OUTBYTES];
    crypto_hash( hash, buf, i );

    EXPECT_TRUE(0 == memcmp( hash, blake2b_kat[i], BLAKE2B_OUTBYTES ) );
  }
}
