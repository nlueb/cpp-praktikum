#include "rational.hpp"

#include <numeric>

using std::cout, std::endl, std::ostream, std::to_string;

Rational::Rational()
    : Rational(1, 2)
{
}

Rational::Rational(int counter, int denominator)
    : counter { counter }
    , denominator { denominator }
{
    cout << "Rational " << (*this) << " created." << endl;
}

Rational::Rational(const Rational& rational)
    : Rational(rational.counter, rational.denominator)
{
}

Rational::~Rational()
{
    cout << "Rational " << (*this) << " deleted." << endl;
}

void Rational::simplify()
{
    int gcd = std::gcd(counter, denominator);

    counter /= gcd;
    denominator /= gcd;
}

ostream& operator<<(ostream& os, const Rational& rational)
{
    os << to_string(rational.counter) << "/" << to_string(rational.denominator);
    return os;
}

Rational operator+(const Rational& a, const Rational& b)
{
    return Rational(a.counter * b.denominator + b.counter * a.denominator,
                    a.denominator * b.denominator);
}

Rational operator-(const Rational& a, const Rational& b)
{
    return a + (-b);
}

Rational operator*(const Rational& a, const Rational& b)
{
    return Rational(a.counter * b.counter,
                    a.denominator * b.denominator);
}

Rational operator/(const Rational& a, const Rational& b)
{
    return Rational(a.counter * b.denominator,
                    a.denominator * b.counter);
}

bool operator<(const Rational& a, const Rational& b)
{
    return (a.counter * b.denominator) < (b.counter * a.denominator);
}


Rational Rational::operator-() const
{
    return Rational(-counter, denominator);
}

Rational simplify(const Rational& rational)
{
    int gcd = std::gcd(rational.counter, rational.denominator);

    return Rational(rational.counter / gcd,
                    rational.denominator / gcd);
}
