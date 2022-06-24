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

FieldPos::FieldPos(std::size_t row, std::size_t col)
    : row { row }
    , col { col }
{
}

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
    : fields { BOARD_SIZE, { BOARD_SIZE, Field::EMPTY } }
{
}

std::optional<GameStatus> Board::whoWon() const
{
    using std::cbegin, std::cend, std::ranges::all_of, std::ranges::any_of;
    const auto are = [this](const Field which) {
        return [this, which](const FieldPos& pos) {
            return fields[pos.row][pos.col] == which;
        };
    };
    for (const auto& fields_to_check : win_conditions) {
        if (all_of(fields_to_check, are(Field::CROSS))) {
            return GameStatus::CROSS;
        }
        if (all_of(fields_to_check, are(Field::CIRCLE))) {
            return GameStatus::CIRCLE;
        }
    }
    if (any_of(fields, [](const auto& row) {
            return any_of(row, [](Field field) {
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
    for (std::size_t i_row = 0; i_row < BOARD_SIZE; ++i_row) {
        for (std::size_t i_col = 0; i_col < BOARD_SIZE; ++i_col) {
            if (fields[i_row][i_col] == Field::EMPTY) {
                empty_fields.emplace_back(i_row, i_col);
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
