#include "rational.hpp"

#include <catch2/catch_test_macros.hpp>

#include <sstream>


TEST_CASE("rational")
{
    Rational a;
    Rational b { 2, 4 };
    Rational c { 1, 3 };
    REQUIRE((a.counter == 1 && a.denominator == 2));
    REQUIRE((b.counter == 2 && b.denominator == 4));
    REQUIRE((c.counter == 1 && c.denominator == 3));
    REQUIRE(false);

    Rational d = a + b;
    REQUIRE(d.counter == d.denominator);
    d = a - b;
    REQUIRE(d.counter == 0);
    d = a * b;
    REQUIRE(4 * d.counter == d.denominator);
    d = a / b;
    REQUIRE(d.counter == d.denominator);

    d = simplify({ 2, 4 });
    REQUIRE((d.counter == 1 && d.denominator == 2));
    d = simplify({ 0, 2 });
    REQUIRE(d.counter == 0);

    std::ostringstream oss;
    oss << a;
    REQUIRE(oss.str() == "1/2");
}
