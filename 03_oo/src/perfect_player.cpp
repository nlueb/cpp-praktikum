#include "perfect_player.hpp"

#include <iostream>
#include <tuple>

typedef std::tuple<int, unsigned int, unsigned int> MaxTuple;

PerfectPlayer::PerfectPlayer(Color color)
    : Player(color)
{
}

int min(Board& board, Color color);

MaxTuple max(Board& board, Color color)
{
    MaxTuple best_result { -2, 0, 0 };

    for (unsigned i = 0; i < 3; i++) {
        for (unsigned j = 0; j < 3; j++) {
            int result;
            if (board[i][j] == Field::EMPTY) {
                board[i][j] = asField(color);
                if (board.whoWon().has_value()) {
                    GameStatus res = board.whoWon().value();
                    if (res == GameStatus::TIE)
                        result = 0;
                    if (res == asGameStatus(color))
                        result = 1;
                    if (res == asGameStatus(enemyOf(color)))
                        result = -1;
                } else {
                    result = min(board, color);
                }
                if (result > std::get<0>(best_result)) {
                    best_result = MaxTuple { result, i, j };
                }
                board[i][j] = Field::EMPTY;
            }
        }
    }
    return best_result;
}

int min(Board& board, Color color)
{
    int best_result = 2;

    for (unsigned i = 0; i < 3; i++) {
        for (unsigned j = 0; j < 3; j++) {
            int result;
            if (board[i][j] == Field::EMPTY) {
                board[i][j] = color == Color::CIRCLE ? Field::CROSS : Field::CIRCLE;
                if (board.whoWon().has_value()) {
                    GameStatus res = board.whoWon().value();
                    if (res == GameStatus::TIE)
                        result = 0;
                    if (res == asGameStatus(color))
                        result = 1;
                    if (res == asGameStatus(enemyOf(color)))
                        result = -1;
                } else {
                    result = std::get<0>(max(board, color));
                }
                if (result < best_result) {
                    best_result = result;
                }
                board[i][j] = Field::EMPTY;
            }
        }
    }
    return best_result;
}

void PerfectPlayer::performNextMove(Board& board)
{
    MaxTuple best_move = max(board, color);
    board[std::get<1>(best_move)][std::get<2>(best_move)] = asField(color);
}
