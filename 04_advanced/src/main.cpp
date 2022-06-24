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
    std::string str = "aAaAb$$$$$$$$$a";
    // 4.1a)
    std::cout << "4.1a) anzahl Abc = " << countAbc(str) << std::endl;

    // 4.1b)
    auto mep = countIndividual("saWhyIHNlaWQgZG9jaCBrYWNrZQ==");
    std::cout << "4.1b) countIndividual " << std::endl;

    for (const auto& [key, value] : mep) {
        std::cout << '\t' << key << " -> " << value << std::endl;
    }

    // 4.1c) Verwendung der Klasse SymbolCounter
    SymbolCounter sc({ 'a', 'A', '$' });
    size_t anzahl = std::count_if(str.begin(), str.end(), sc);
    std::cout << "4.1c) anzahl aA$ = " << anzahl << std::endl;

    // 4.1d)
    auto chars = usedSymbols(str);
    std::cout << "4.1d) unique chars in " << str << ": ";
    for (const auto c : chars)
        std::cout << c;
    std::cout << std::endl;

    // 4.2a)
    auto fx = [](double x) { return std::pow(x, 3) + 4 * std::pow(x, 2) - 7 * x + 12; };
    auto fderiv = [](float x) { return 3 * std::pow(x, 2) + 8 * x - 7; };
    double solution = newton(fx, fderiv, 0, 1000);
    std::cout << "4.2 a): " << solution << std::endl;

    print_newtonTemp<float>();
    print_newtonTemp<double>();
    print_newtonTemp<unsigned int>();
    print_newtonTemp<int>();
}
