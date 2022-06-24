#include "human_player.hpp"

#include "board.hpp"
#include "util.hpp"

#include <cstddef>
#include <iostream>
#include <regex>

HumanPlayer::HumanPlayer(Color color)
    : Player(color)
{
}

FieldPos HumanPlayer::getUserInput()
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
        readline(input);
    } while (!std::regex_search(input, matches, re));

    return FieldPos(std::stoi(matches[1].str()), std::stoi(matches[2].str()));
}

void HumanPlayer::performNextMove(Board& board)
{
    FieldPos pos { 1337, 69 };
    do {
        if (pos != FieldPos(1337, 69))
            std::cout << "Hör auf zu cheaten!" << std::endl;
        pos = getUserInput();
    } while (board[pos.row][pos.col] != Field::EMPTY);
    std::cout << "Alles klar!" << std::endl;
    board[pos.row][pos.col] = asField(this->color);
}
