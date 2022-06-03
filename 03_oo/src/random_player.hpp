#pragma once
#include "player.hpp"

class RandomPlayer : virtual public Player {
public:
    RandomPlayer(Color color);

public:
    virtual void performNextMove(Board& board) override;
};
