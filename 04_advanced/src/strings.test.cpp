#include <catch2/catch_test_macros.hpp>

#include "strings.hpp"

TEST_CASE("strings") {
    REQUIRE(countAbc("") == 0);
    REQUIRE(countAbc("@") == 0);
    REQUIRE(countAbc("A") == 1);
    REQUIRE(countAbc("Z") == 1);
    REQUIRE(countAbc("[") == 0);
    REQUIRE(countAbc("`") == 0);
    REQUIRE(countAbc("a") == 1);
    REQUIRE(countAbc("z") == 1);
    REQUIRE(countAbc("{") == 0);
    REQUIRE(countAbc("abcdefghijklmnopqrstuvwxyz") == 26);
    REQUIRE(countAbc("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 26);
}
