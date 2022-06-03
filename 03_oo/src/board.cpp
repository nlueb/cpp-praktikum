#include "board.hpp"

#include "player.hpp"

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iterator>
#include <optional>
#include <tuple>
#include <utility>
#include <vector>

constexpr std::size_t BOARD_SIZE = 3;

GameStatus asGameStatus(Color color)
{
    switch (color) {
    case Color::CROSS:
        return GameStatus::CROSS;
    default:
        return GameStatus::CIRCLE;
    }
}

GameStatus asGameStatus(Field field)
{
    switch (field) {
    case Field::CROSS:
        return GameStatus::CROSS;
    case Field::CIRCLE:
        return GameStatus::CIRCLE;
    default:
        std::abort();
    }
}

Field asField(Color color)
{
    switch (color) {
    case Color::CROSS:
        return Field::CROSS;
    default:
        return Field::CIRCLE;
    }
}

Color enemyOf(Color color)
{
    switch (color) {
    case Color::CROSS:
        return Color::CIRCLE;
    default:
        return Color::CROSS;
    }
}

Board::Board()
    : fields(std::vector<std::vector<Field>>(
        BOARD_SIZE, std::vector<Field>(BOARD_SIZE, Field::EMPTY)))
{
}

std::optional<GameStatus> Board::whoWon() const
{
    for (const auto& win_condition : win_conditions) {
        if (std::all_of(std::begin(win_condition), std::end(win_condition), [this](const auto& x) {
                return fields[x.first][x.second] == Field::CROSS;
            })) {
            return GameStatus::CROSS;
        }
        if (std::all_of(std::begin(win_condition), std::end(win_condition), [this](const auto& x) {
                return fields[x.first][x.second] == Field::CIRCLE;
            })) {
            return GameStatus::CIRCLE;
        }
    }
    if (std::any_of(std::begin(fields), std::end(fields), [](const auto& row) {
            return std::any_of(std::begin(row), std::end(row), [](Field field) {
                return field == Field::EMPTY;
            });
        })) {
        return std::nullopt;
    }
    return GameStatus::TIE;
}

std::vector<FieldPos> Board::get_emtpy_fields() const
{
    std::vector<FieldPos> empty_fields;
    for (std::size_t i = 0; i < BOARD_SIZE; ++i) {
        for (std::size_t j = 0; j < BOARD_SIZE; ++j) {
            if (fields[i][j] == Field::EMPTY) {
                empty_fields.emplace_back(i, j);
            }
        }
    }
    return empty_fields;
}

std::ostream&
operator<<(std::ostream& os, const Field& field)
{
    return os << (field == Field::CROSS ? "X" : field == Field::CIRCLE ? "O"
                                                                       : " ");
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
    for (const auto& row : board) {
        os << "|";
        for (const auto& field : row) {
            os << " " << field << " |";
        }
        os << "\n";
    }
    return os;
}
