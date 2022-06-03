#pragma once

#include "board.hpp"
#include "player.hpp"

class GameController {
public:
    void play(Player& cross, Player& circle);

private:
    Board board {};
};
