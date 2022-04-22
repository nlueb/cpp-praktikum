#include "rational.hpp"

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

ostream& operator<<(ostream& os, const Rational& rational)
{
    os << to_string(rational.counter) << "/" << to_string(rational.denominator);
    return os;
}
