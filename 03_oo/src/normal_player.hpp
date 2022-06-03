#pragma once
#include "perfect_player.hpp"
#include "random_player.hpp"

class NormalPlayer : public RandomPlayer, public PerfectPlayer {
public:
    NormalPlayer(Color color);

public:
    virtual void performNextMove(Board& board) override;
};
