#include "game_controller.hpp"

#include "board.hpp"

#include <iostream>
#include <vector>

void GameController::play(Player& cross, Player& circle)
{
    const std::vector<Player*> players = { &cross, &circle };
    int current = std::rand() % 2;

    std::cout << board << std::endl;
    while (board.whoWon() == std::nullopt) {
        players[current]->performNextMove(board);
        std::cout << board << std::endl;
        current = (current + 1) % 2;
    }
}
