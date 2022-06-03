#include "human_player.hpp"

#include "util.test.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <sstream>

TEST_CASE("human player")
{
    SECTION("circle")
    {
        std::streambuf* orig = std::cin.rdbuf();
        std::istringstream input("0 0");
        std::cin.rdbuf(input.rdbuf());
        HumanPlayer player(Color::CIRCLE);
        test_single_move(player, Field::CIRCLE);
        std::cin.rdbuf(orig);
    }
    SECTION("cross")
    {
        std::streambuf* orig = std::cin.rdbuf();
        std::istringstream input("0 0");
        std::cin.rdbuf(input.rdbuf());
        HumanPlayer player(Color::CROSS);
        test_single_move(player, Field::CROSS);
        std::cin.rdbuf(orig);
    }
}
