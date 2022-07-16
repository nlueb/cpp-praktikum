#include <catch2/catch_test_macros.hpp>

extern "C" {
#include "registers.h"
}

TEST_CASE("registers")
{
    Register_t original = 0xa14c99f7;
    Register_t expected = 0x9ec0d9f7;

    Register_t copy = original;
    REQUIRE(ADCCON3 == original);
    setRegisters(&copy);
    REQUIRE(ADCCON3 == original);
    REQUIRE(copy == expected);

    copy = original;
    REQUIRE(ADCCON3 == original);
    setRegistersStruct(&copy);
    REQUIRE(ADCCON3 == original);
    REQUIRE(copy == expected);
}
