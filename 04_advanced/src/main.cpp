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

template <typename T>
void print_newtonTemp()
{
    T solutionTemp = newtonTemp<T>(fxTemp<T>, fderivTemp<T>, 0, 1000);
    std::cout << "4.2 b) " << typeid(T).name() << " : " << solutionTemp << std::endl;
}

int main()
{
    auto mep = countIndividual("saWhyIHNlaWQgZG9jaCBrYWNrZQ==");
    for (const auto& [key, value] : mep) {
        std::cout << key << " -> " << value << std::endl;
    }

    auto fx = [](double x) { return std::pow(x, 3) + 4 * std::pow(x, 2) - 7 * x + 12; };
    auto fderiv = [](float x) { return 3 * std::pow(x, 2) + 8 * x - 7; };
    double solution = newton(fx, fderiv, 0, 1000);
    std::cout << "4.2 a): " << solution << std::endl;

    print_newtonTemp<float>();
    print_newtonTemp<double>();
    print_newtonTemp<unsigned int>();
    print_newtonTemp<int>();
}
