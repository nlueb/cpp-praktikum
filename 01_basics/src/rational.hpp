#pragma once

#include <iostream>

class Rational {
public:
    int counter, denominator;

    // Constructors
    Rational();
    Rational(const int, const int);
    Rational(const Rational&);
    ~Rational();

    void simplify();

    // Output
    friend std::ostream& operator<<(std::ostream&, const Rational&);

    // Operators - Binary
    friend Rational operator+(const Rational&, const Rational&);
    friend Rational operator-(const Rational&, const Rational&);
    friend Rational operator*(const Rational&, const Rational&);
    friend Rational operator/(const Rational&, const Rational&);
    friend bool operator<(const Rational&, const Rational&);

    // Operators - Unary
    Rational operator-() const;
};

Rational simplify(const Rational&);
