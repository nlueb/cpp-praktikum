#pragma once
#include "player.hpp"

class PerfectPlayer : virtual public Player {
public:
    PerfectPlayer(Color color);

public:
    virtual void performNextMove(Board& board) override;
};
