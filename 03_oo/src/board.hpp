#pragma once
#include <array>
#include <cstddef>
#include <iterator>
#include <optional>
#include <ostream>
#include <vector>

class Player;

enum class GameStatus {
    CROSS,
    CIRCLE,
    TIE
};

enum class Field {
    CROSS,
    CIRCLE,
    EMPTY
};

enum class Color {
    CROSS,
    CIRCLE
};

struct FieldPos {
    std::size_t row;
    std::size_t col;

    FieldPos(std::size_t, std::size_t);

    // NOTE: These are also generated ==, !=, <, <=, >, and >=
    bool operator<=>(const FieldPos&) const = default;
};

GameStatus asGameStatus(Color color);
GameStatus asGameStatus(Field field);
Field asField(Color color);
Color enemyOf(Color color);

class Board {
    using Fields = std::vector<std::vector<Field>>;
    Fields fields;

    const std::array<std::array<FieldPos, 3>, 8> win_conditions { {
        // Rows
        { FieldPos(0, 0), FieldPos(0, 1), FieldPos(0, 2) },
        { FieldPos(1, 0), FieldPos(1, 1), FieldPos(1, 2) },
        { FieldPos(2, 0), FieldPos(2, 1), FieldPos(2, 2) },
        // Columns
        { FieldPos(0, 0), FieldPos(1, 0), FieldPos(2, 0) },
        { FieldPos(0, 1), FieldPos(1, 1), FieldPos(2, 1) },
        { FieldPos(0, 2), FieldPos(1, 2), FieldPos(2, 2) },
        // Diagnoals
        { FieldPos(0, 0), FieldPos(1, 1), FieldPos(2, 2) },
        { FieldPos(0, 2), FieldPos(1, 1), FieldPos(2, 0) },
    } };

public:
    Board();

    auto begin() const { return std::begin(fields); }
    auto end() const { return std::end(fields); }
    std::vector<Field>& operator[](size_t i) { return fields[i]; }
    const std::vector<Field>& operator[](size_t i) const { return fields[i]; }

    std::optional<GameStatus> whoWon() const;

    std::vector<FieldPos> get_emtpy_fields() const;
};

std::ostream& operator<<(std::ostream& os, const Field& field);

std::ostream& operator<<(std::ostream& os, const Board& board);
