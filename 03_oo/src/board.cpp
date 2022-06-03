#include "board.hpp"

#include "player.hpp"

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
        3, std::vector<Field>(3, Field::EMPTY)))
{
}

std::optional<GameStatus> Board::whoWon() const
{
    return {}; // TODO
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
    // TODO
    return os;
}
