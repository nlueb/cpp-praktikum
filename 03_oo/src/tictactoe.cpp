#include "board.hpp"
#include "game_controller.hpp"
#include "human_player.hpp"
#include "normal_player.hpp"
#include "perfect_player.hpp"
#include "random_player.hpp"
#include "util.hpp"

#include <csignal>
#include <ctime>
#include <iostream>
#include <regex>
#include <string>

Player* get_enemy(const Color color)
{
    std::string input;
    const std::regex re { "^[1-4]$" };
    std::smatch matches;

    do {
        if (matches.ready()) {
            std::cout << "Eingabe ist ungültig." << std::endl;
        }
        std::cout << "Gegen wen wollen Sie spielen?"
                  << "\n\t1) Human Player"
                  << "\n\t2) Random Player"
                  << "\n\t3) Normal Player"
                  << "\n\t4) Perfect Player"
                  << "\n>> " << std::flush;
        readline(input);
    } while (!std::regex_search(input, matches, re));
    std::cout << "Alles klar!" << std::endl;

    switch (stoi(matches[0])) {
    case 1:
        return new HumanPlayer(color);
    case 2:
        return new RandomPlayer(color);
    case 3:
        return new NormalPlayer(color);
    case 4:
    default:
        return new PerfectPlayer(color);
    }
}

void handle_interrupt(__attribute__((unused)) int signal)
{
    std::cout << "Bye." << std::endl;
    exit(0);
}

int main()
{
    std::signal(SIGINT, handle_interrupt);
    std::srand(std::time(nullptr));
    HumanPlayer playerA { Color::CROSS };
    Player* playerB = get_enemy(Color::CIRCLE);
    GameController().play(playerA, *playerB);
    delete playerB;
}
