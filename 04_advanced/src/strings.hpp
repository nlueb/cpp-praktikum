#pragma once
#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

bool isValidChar(char c);

size_t countAbc(const std::string& input);

std::map<char, size_t> countIndividual(const std::string& input);

std::list<char> usedSymbols(const std::string& input);

class SymbolCounter {
    std::string schtring;

public:
    explicit SymbolCounter(std::initializer_list<char> lst);

    bool operator()(char c) const;
};
