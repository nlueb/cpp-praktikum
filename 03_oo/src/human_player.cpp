#include "human_player.hpp"

#include <iostream>
#include <regex>

HumanPlayer::HumanPlayer(Color color)
    : Player(color)
{
}

std::pair<std::size_t, std::size_t> HumanPlayer::getUserInput()
{
    std::string input;
    std::regex re { "^([012]) ([012])$" };
    std::smatch matches;

    do {
        if (matches.ready()) {
            std::cout << "Eingabe ist ungültig." << std::endl;
        }
        std::cout << "Wo wollen Sie ihr Kreuz setzen? (Zählend von 0)" << std::endl;
        std::cout << "Eingabeformat: <Zeile> <Spalte>, zum Beispiel '2 0':\n>> " << std::flush;
        std::getline(std::cin, input);
    } while (!std::regex_search(input, matches, re));

    std::cout << "Alles klar!" << std::endl;
    return { std::stoi(matches[1].str()), std::stoi(matches[2].str()) };
}

void HumanPlayer::performNextMove(Board& board)
{
    const auto [i, j] = getUserInput();
    board[i][j] = asField(this->color);
}
