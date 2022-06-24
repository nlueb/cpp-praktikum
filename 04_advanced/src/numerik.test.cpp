#include <catch2/catch_test_macros.hpp>

#include "numerik.hpp"

TEST_CASE("numerik") {
    REQUIRE(fxTemp<int>(0) == 12);
    REQUIRE(fxTemp<int>(1) == 10);
    REQUIRE(fxTemp<int>(2) == 22);

    REQUIRE(fderivTemp<int>(0) == -7);
    REQUIRE(fderivTemp<int>(1) == 4);
    REQUIRE(fderivTemp<int>(2) == 21);

    REQUIRE(newton(fxTemp<double>, fderivTemp<float>, -5, 10) + 5.6240 < 0.0001);
    REQUIRE(newtonTemp<double>(fxTemp<double>, fderivTemp<double>, -5, 10) + 5.6240 < 0.0001);
}
