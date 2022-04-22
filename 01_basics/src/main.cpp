#include "rational.hpp"

#include <iostream>

using std::cout, std::endl;

int main()
{
    // Task 1.1b)
    Rational a(1, 4);
    Rational b(1, 2);

    cout << "Task 1.1b)" << endl;
    cout << '\t' << "a = " << a << endl;
    cout << '\t' << "b = " << b << endl;

    // Task 1.1c)
    Rational c = b + a;
    Rational d = b - a;
    Rational e = b * a;
    Rational f = b / a;

    cout << "Task 1.1c) I" << endl;
    cout << '\t' << "c = " << b << " + " << a << " = " << c << endl;
    cout << '\t' << "d = " << b << " - " << a << " = " << d << endl;
    cout << '\t' << "e = " << b << " * " << a << " = " << e << endl;
    cout << '\t' << "f = " << b << " / " << a << " = " << f << endl;

    // Task 1.1c)
    Rational& min = c;
    for (const Rational* r : { &c, &d, &e, &f }) {
        if (*r < min)
            min = *r;
    }

    cout << "Task 1.1c) II" << endl;
    cout << '\t' << "min = " << min << endl;

    // Task 1.1d)
    c.simplify();
    d.simplify();
    e.simplify();
    f.simplify();

    cout << "Task 1.1d)" << endl;
    cout << '\t' << "c = " << c << endl;
    cout << '\t' << "d = " << d << endl;
    cout << '\t' << "e = " << e << endl;
    cout << '\t' << "f = " << f << endl;

    return 0;
}
