#include "normal_player.hpp"

#include "util.test.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("normal player")
{
    SECTION("circle")
    {
        NormalPlayer player(Color::CIRCLE);
        test_single_move(player, Field::CIRCLE);
    }
    SECTION("cross")
    {
        NormalPlayer player(Color::CROSS);
        test_single_move(player, Field::CROSS);
    }
}
