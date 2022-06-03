#include "human_player.hpp"

#include "board.hpp"

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
        std::getline(std::cin, input);
    } while (!std::regex_search(input, matches, re));

    return { std::stoi(matches[1].str()), std::stoi(matches[2].str()) };
}

void HumanPlayer::performNextMove(Board& board)
{
    auto empty_fields = board.get_emtpy_fields();
    FieldPos pos { 1337, 69 };
    do {
        if (pos != FieldPos(1337, 69))
            std::cout << "Hör auf zu cheaten!" << std::endl;
        pos = getUserInput();
    } while (board[pos.first][pos.second] != Field::EMPTY);
    std::cout << "Alles klar!" << std::endl;
    board[pos.first][pos.second] = asField(this->color);
}
