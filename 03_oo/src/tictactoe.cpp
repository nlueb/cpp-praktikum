#include "game_controller.hpp"
#include "human_player.hpp"
#include "normal_player.hpp"
#include "board.hpp"

#include <iostream>
#include <string>

int main()
{
    Board board{};
    HumanPlayer player{Color::CROSS};
    player.performNextMove(board);
    std::cout << board << std::endl;
}
