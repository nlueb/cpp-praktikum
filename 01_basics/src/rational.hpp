#pragma once

#include <iostream>

using namespace std;

class Rational {
public:
    int counter;
    int denominator;

    friend ostream& operator<<(ostream& os, const Rational &rational);

    Rational();

    Rational(int num, int denom);

    Rational(const Rational &rational);

    ~Rational();

};