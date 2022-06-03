#pragma once

#include "player.hpp"

class HumanPlayer : public Player {
public:
    HumanPlayer(Color color);

public:
    virtual void performNextMove(Board& board) override;

private:
    std::pair<std::size_t, std::size_t> getUserInput();
};
