#include "numerik.hpp"
#include "strings.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

int main(int argc, char** argv)
{
    auto fx = [](double x){ return std::pow(x, 3) + 4 * std::pow(x, 2) - 7 * x + 12; };
    auto fderiv = [](float x){ return 3 * std::pow(x, 2) + 8 * x - 7; };
    double solution = newton(fx, fderiv, 0, 1000);
    std::cout << "4.2 a): " << solution << std::endl;
}
