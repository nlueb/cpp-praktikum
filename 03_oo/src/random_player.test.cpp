#include "random_player.hpp"

#include "util.test.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("random player")
{
    SECTION("circle")
    {
        RandomPlayer player(Color::CIRCLE);
        test_single_move(player, Field::CIRCLE);
    }
    SECTION("cross")
    {
        RandomPlayer player(Color::CROSS);
        test_single_move(player, Field::CROSS);
    }
}
