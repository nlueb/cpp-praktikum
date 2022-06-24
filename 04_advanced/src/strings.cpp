#include "strings.hpp"

#include <algorithm>
#include <cctype>
#include <iterator>
#include <numeric>

bool isValidChar(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

size_t countAbc(const std::string& input)
{
    return std::count_if(std::begin(input), std::end(input), isValidChar);
}

std::map<char, size_t> countIndividual(const std::string& input)
{
    std::map<char, size_t> map;
    for (char c : input) {
        if (!isValidChar(c)) {
            continue;
        }
        c = static_cast<char>(std::tolower(c));
        map[c] = map.count(c) + 1;
    }
    return map;
}

SymbolCounter::SymbolCounter(std::initializer_list<char> lst) /* TODO */ { }

bool SymbolCounter::operator()(char c) const
{
    // TODO
}

std::list<char> usedSymbols(const std::string& input)
{
    // TODO
}
