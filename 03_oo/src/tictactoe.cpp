#include "game_controller.hpp"
#include "human_player.hpp"
#include "normal_player.hpp"
#include "board.hpp"

#include <ctime>
#include <iostream>
#include <string>

int main()
{
    std::srand(std::time(nullptr));
    Board board{};
    RandomPlayer player{Color::CROSS};
    player.performNextMove(board);
    std::cout << board << std::endl;
}
