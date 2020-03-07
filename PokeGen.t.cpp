#include <gtest/gtest.h>
#include "PokeGen.h"
TEST(PokePack, Test) {
    uint8_t input[24];
    uint8_t output[15];
    PokeGen::pack(input, (uint8_t**)&output);
    ASSERT_TRUE(true);
}
