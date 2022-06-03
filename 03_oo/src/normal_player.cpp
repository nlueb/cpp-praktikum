#include "normal_player.hpp"

#include <cstdlib>

NormalPlayer::NormalPlayer(Color color)
    : PerfectPlayer(color)
    , RandomPlayer(color)
    , Player(color)
{
}

void NormalPlayer::performNextMove(Board& board)
{
    // TODO
}
