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

int main()
{
    auto mep = countIndividual("aWhyIHNlaWQgZG9jaCBrYWNrZQ==");
    for (const auto& [key, value] : mep) {
        std::cout << key << " -> " << value << std::endl;
    }
}
