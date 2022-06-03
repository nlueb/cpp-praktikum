#pragma once

#include "player.hpp"

class HumanPlayer : public Player {
public:
    HumanPlayer(Color color);

public:
    virtual void performNextMove(Board& board) override;

private:
    FieldPos getUserInput();
};
