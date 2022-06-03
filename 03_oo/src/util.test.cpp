#include "util.test.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>

void test_single_move(Player& player, Field expectedField)
{
    Board board;
    bool has_non_empty = false;
    player.performNextMove(board);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == expectedField) {
                has_non_empty = true;
            } else {
                REQUIRE(board[i][j] == Field::EMPTY);
            }
        }
    }
    REQUIRE(has_non_empty);
}
