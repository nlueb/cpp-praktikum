#include "board.hpp"
#include "game_controller.hpp"
#include "human_player.hpp"
#include "normal_player.hpp"
#include "perfect_player.hpp"
#include "random_player.hpp"

#include <ctime>
#include <iostream>
#include <regex>
#include <string>

Player* get_enemy()
{
    std::string input;
    std::regex re { "^([1-4])$" };
    std::smatch matches;

    do {
        if (matches.ready()) {
            std::cout << "Eingabe ist ungültig." << std::endl;
        }
        std::cout << "Gegen wen wollen Sie spielen?";
        std::cout << "\n\t1) Human Player";
        std::cout << "\n\t2) Random Player";
        std::cout << "\n\t3) Normal Player";
        std::cout << "\n\t4) Perfect Player"
                  << "\n>> " << std::flush;
        std::getline(std::cin, input);
    } while (!std::regex_search(input, matches, re));
    std::cout << "Alles klar!" << std::endl;

    switch (stoi(matches[1])) {
    case 1:
        return new HumanPlayer(Color::CIRCLE);
    case 2:
        return new RandomPlayer(Color::CIRCLE);
    case 3:
        return new NormalPlayer(Color::CIRCLE);
    case 4:
        return new PerfectPlayer(Color::CIRCLE);
    }
}

int main()
{
    std::srand(std::time(nullptr));
    HumanPlayer playerA { Color::CROSS };
    Player* playerB = get_enemy();
    GameController().play(playerA, *playerB);
    delete playerB;
}
