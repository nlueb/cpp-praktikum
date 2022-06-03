#pragma once
#include <optional>
#include <ostream>
#include <vector>

class Player;

enum class GameStatus { CROSS,
                        CIRCLE,
                        TIE };

enum class Field { CROSS,
                   CIRCLE,
                   EMPTY };

enum class Color { CROSS,
                   CIRCLE };

GameStatus asGameStatus(Color color);
GameStatus asGameStatus(Field field);
Field asField(Color color);
Color enemyOf(Color color);

class Board {
    using Fields = std::vector<std::vector<Field>>;
    Fields fields;

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

public:
    Board();

    auto begin() const { return fields.begin(); }
    auto end() const { return fields.end(); }
    std::vector<Field>& operator[](size_t i) { return fields[i]; }
    const std::vector<Field>& operator[](size_t i) const { return fields[i]; }

    std::optional<GameStatus> whoWon() const;
};

std::ostream& operator<<(std::ostream& os, const Field& field);

std::ostream& operator<<(std::ostream& os, const Board& board);
