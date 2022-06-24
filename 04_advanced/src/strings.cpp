#include "strings.hpp"

#include <algorithm>
#include <cctype>
#include <iterator>

size_t countAbc(const std::string& input)
{
    return std::count_if(std::begin(input), std::end(input), [](char c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); });
}

std::map<char, size_t> countIndividual(const std::string& input)
{
    std::map<char, size_t> map;
    // auto lowInput = std::tolower();
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
