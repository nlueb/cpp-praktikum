#include "normal_player.hpp"

#include "random_player.hpp"

#include <cstdlib>
#include <iostream>

NormalPlayer::NormalPlayer(Color color)
    : Player(color)
    , RandomPlayer(color)
    , PerfectPlayer(color)
{
}

void NormalPlayer::performNextMove(Board& board)
{
    std::rand() % 2 == 1 ? RandomPlayer::performNextMove(board)
                         : PerfectPlayer::performNextMove(board);
}
