#include "board.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("board")
{
    Board board;

    SECTION("no winner")
    {
        SECTION("empty board") { }
        SECTION("full row")
        {
            board[0][0] = Field::CIRCLE;
            board[0][1] = Field::CROSS;
            board[0][2] = Field::CIRCLE;
        }
        SECTION("full column")
        {
            board[0][0] = Field::CIRCLE;
            board[1][0] = Field::CROSS;
            board[2][0] = Field::CIRCLE;
        }
        SECTION("diagonal 1")
        {
            board[0][0] = Field::CIRCLE;
            board[1][1] = Field::CROSS;
            board[2][2] = Field::CIRCLE;
        }
        SECTION("diagonal 2")
        {
            board[0][2] = Field::CIRCLE;
            board[1][1] = Field::CROSS;
            board[2][0] = Field::CIRCLE;
        }
        REQUIRE(!board.whoWon().has_value());
    }

    SECTION("circle wins")
    {
        SECTION("full row")
        {
            board[0][0] = Field::CIRCLE;
            board[0][1] = Field::CIRCLE;
            board[0][2] = Field::CIRCLE;
        }
        SECTION("full column")
        {
            board[0][0] = Field::CIRCLE;
            board[1][0] = Field::CIRCLE;
            board[2][0] = Field::CIRCLE;
        }
        SECTION("full row")
        {
            board[2][0] = Field::CIRCLE;
            board[2][1] = Field::CIRCLE;
            board[2][2] = Field::CIRCLE;
        }
        SECTION("full column")
        {
            board[0][2] = Field::CIRCLE;
            board[1][2] = Field::CIRCLE;
            board[2][2] = Field::CIRCLE;
        }
        SECTION("diagonal 1")
        {
            board[0][0] = Field::CIRCLE;
            board[1][1] = Field::CIRCLE;
            board[2][2] = Field::CIRCLE;
        }
        SECTION("diagonal 2")
        {
            board[0][2] = Field::CIRCLE;
            board[1][1] = Field::CIRCLE;
            board[2][0] = Field::CIRCLE;
        }
        REQUIRE(board.whoWon().has_value());
        REQUIRE(board.whoWon().value() == GameStatus::CIRCLE);
    }

    SECTION("cross wins")
    {
        SECTION("full row")
        {
            board[1][0] = Field::CROSS;
            board[1][1] = Field::CROSS;
            board[1][2] = Field::CROSS;
        }
        SECTION("full column")
        {
            board[0][1] = Field::CROSS;
            board[1][1] = Field::CROSS;
            board[2][1] = Field::CROSS;
        }
        SECTION("diagonal 1")
        {
            board[0][0] = Field::CROSS;
            board[1][1] = Field::CROSS;
            board[2][2] = Field::CROSS;
        }
        SECTION("diagonal 2")
        {
            board[0][2] = Field::CROSS;
            board[1][1] = Field::CROSS;
            board[2][0] = Field::CROSS;
        }
        REQUIRE(board.whoWon().has_value());
        REQUIRE(board.whoWon().value() == GameStatus::CROSS);
    }
}
