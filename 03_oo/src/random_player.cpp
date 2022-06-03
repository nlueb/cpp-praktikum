#include "random_player.hpp"

#include <cstdlib>

RandomPlayer::RandomPlayer(Color color)
    : Player(color)
{
}

void RandomPlayer::performNextMove(Board& board)
{
    const auto empty_fields = board.get_emtpy_fields();
    const std::size_t random_index = std::rand() % empty_fields.size();
    const auto [i, j] = empty_fields[random_index];
    board[i][j] = asField(color);
}
