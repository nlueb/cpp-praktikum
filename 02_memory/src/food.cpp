#include "food.hpp"

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

Food::Food(int bestellnummer, std::string bezeichnung, float preis)
    : bestellnr(bestellnummer)
    , bezeichnung(bezeichnung)
    , preis(preis)
{
}

std::string Food::getBezeichnung() const { return bezeichnung; }

float Food::getPreis() const { return preis; }

int Food::getBestellnummer() const { return bestellnr; }

std::string Food::getCSV() const
{
    std::stringstream ss;
    ss << bestellnr << ';' << bezeichnung << ';' << preis << '\n';
    return ss.str();
}

void speichern(const std::string& dateiname, const std::vector<Food>& speisen)
{
    std::ofstream os { dateiname };

    for (const Food& food : speisen) {
        os << food.getCSV();
    }

    os.close();
}

void laden(const std::string& dateiname, std::vector<Food>& speisen)
{
    std::ifstream is { dateiname };
    std::string line;
    std::regex re { "^(\\d+);([\\w\\s]+);([\\d]+\\.?[\\d]*)$" };
    std::smatch match;

    // Regex capture groups
    constexpr std::size_t ORDER_NUMBER = 1;
    constexpr std::size_t NAME = 2;
    constexpr std::size_t PRICE = 3;

    if (!is.is_open()) {
        throw std::runtime_error("Could not open file '" + dateiname + "'.");
    }

    while (std::getline(is, line)) {
        if (std::regex_search(line, match, re)) {
            speisen.emplace_back(std::stoi(match[ORDER_NUMBER]), match[NAME], std::stof(match[PRICE]));
        } else {
            throw std::runtime_error("Error reading '" + dateiname + "'.\nLine '" + line + "' does not apply to the expected structure of 'int;string;float'.");
        }
    }
}
