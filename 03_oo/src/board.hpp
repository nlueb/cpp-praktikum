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

public:
    Board();

    auto begin() const { return fields.begin(); }
    auto end() const { return fields.end(); }
    std::vector<Field>& operator[](size_t i) { return fields[i]; }
    const std::vector<Field>& operator[](size_t i) const { return fields[i]; }

    std::optional<GameStatus> whoWon() const;
};

std::ostream& operator<<(std::ostream& os, const Board& board);
