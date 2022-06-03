#pragma once

#include "board.hpp"

class Player {
public:
    Player(Color color);
    virtual ~Player();

protected:
    Color color;

public:
    virtual void performNextMove(Board& board) = 0;
};
