#include "rational.hpp"

Rational::Rational() {
    counter = 1;
    denominator = 2;

    cout << "Rational " << (*this) << " created." << endl;
}

Rational::Rational(int num, int denom) {
    counter = num;
    denominator = denom;

    cout << "Rational " << (*this) << " created." << endl;
}

Rational::Rational(const Rational &rational) {
    counter = rational.counter;
    denominator = rational.denominator;

    cout << "Rational " << (*this) << " created." << endl;
}

Rational::~Rational() {
    cout << "Rational " << (*this) << " deleted." << endl;
}

ostream& operator<<(ostream& os, const Rational &rational) {
    os << to_string(rational.counter) << "/" << to_string(rational.denominator);
    return os;
}