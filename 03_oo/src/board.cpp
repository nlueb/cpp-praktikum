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

const std::vector<std::vector<std::pair<std::size_t, std::size_t>>> win_conditions {
    { std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2) },
    { std::make_pair(1, 0), std::make_pair(1, 1), std::make_pair(1, 2) },
    { std::make_pair(2, 0), std::make_pair(2, 1), std::make_pair(2, 2) },
    { std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(2, 0) },
    { std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(2, 1) },
    { std::make_pair(0, 2), std::make_pair(1, 2), std::make_pair(2, 2) },
    { std::make_pair(0, 0), std::make_pair(1, 1), std::make_pair(2, 2) },
    { std::make_pair(0, 2), std::make_pair(1, 1), std::make_pair(2, 0) },
};

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

std::ostream& operator<<(std::ostream& os, const Board& board)
{
    // TODO
    return os;
}