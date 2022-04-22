#pragma once

#include <iostream>

class Rational {
public:
    int counter, denominator;

    Rational();
    Rational(const int, const int);
    Rational(const Rational&);
    ~Rational();

    friend std::ostream& operator<<(std::ostream&, const Rational&);
};
