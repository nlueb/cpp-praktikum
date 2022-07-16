#include <catch2/catch_test_macros.hpp>

#include <cstring>

extern "C" {
#include "strings.h"
}

TEST_CASE("concatenate")
{
    auto a = "Hello ";
    auto b = "world!";
    auto expected = "Hello world!";

    auto c = concatenate(a, b);
    REQUIRE(strcmp(c, expected) == 0);
    free(c);
}

TEST_CASE("split")
{
    auto buffer = (char**)malloc(32);
    auto count = -1;

    SECTION("example from the exercise")
    {
        auto src = "Hello;;world;;!";
        count = split(buffer, src, ";;");
        REQUIRE(count == 3);
        REQUIRE(strlen(buffer[0]) == 5);
        REQUIRE(strcmp(buffer[0], "Hello") == 0);
        REQUIRE(strlen(buffer[1]) == 5);
        REQUIRE(strcmp(buffer[1], "world") == 0);
        REQUIRE(strlen(buffer[2]) == 1);
        REQUIRE(strcmp(buffer[2], "!") == 0);
    }

    SECTION("directly consecutive split")
    {
        auto src = "a;;;;b";
        count = split(buffer, src, ";;");
        REQUIRE(count == 3);
        REQUIRE(strlen(buffer[0]) == 1);
        REQUIRE(strcmp(buffer[0], "a") == 0);
        REQUIRE(strlen(buffer[1]) == 0);
        REQUIRE(strcmp(buffer[1], "") == 0);
        REQUIRE(strlen(buffer[2]) == 1);
        REQUIRE(strcmp(buffer[2], "b") == 0);
    }

    SECTION("split at the start of the string")
    {
        auto src = ";;b";
        count = split(buffer, src, ";;");
        REQUIRE(count == 2);
        REQUIRE(strlen(buffer[0]) == 0);
        REQUIRE(strcmp(buffer[0], "") == 0);
        REQUIRE(strlen(buffer[1]) == 1);
        REQUIRE(strcmp(buffer[1], "b") == 0);
    }

    SECTION("split at the end of the string")
    {
        auto src = "a;;";
        count = split(buffer, src, ";;");
        REQUIRE(count == 2);
        REQUIRE(strlen(buffer[0]) == 1);
        REQUIRE(strcmp(buffer[0], "a") == 0);
        REQUIRE(strlen(buffer[1]) == 0);
        REQUIRE(strcmp(buffer[1], "") == 0);
    }

    SECTION("split at the start and the end of the string")
    {
        auto src = ";;";
        count = split(buffer, src, ";;");
        REQUIRE(count == 2);
        REQUIRE(strlen(buffer[0]) == 0);
        REQUIRE(strcmp(buffer[0], "") == 0);
        REQUIRE(strlen(buffer[1]) == 0);
        REQUIRE(strcmp(buffer[1], "") == 0);
    }

    SECTION("no split")
    {
        auto src = "a";
        count = split(buffer, src, ";;");
        REQUIRE(count == 1);
        REQUIRE(strlen(buffer[0]) == 1);
        REQUIRE(strcmp(buffer[0], "a") == 0);
    }

    for (auto i = 0; i < count; ++i) {
        free(buffer[i]);
    }
    free(buffer);
}
