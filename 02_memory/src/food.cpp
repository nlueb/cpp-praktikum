#include "food.hpp"

#include <fstream>
#include <iostream>
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
    std::stringstream ss;
    std::string line, nr, name, preis, trash;

    while (std::getline(is, line)) {
        ss << line;

        std::getline(ss, nr, ';');
        std::getline(ss, name, ';');
        std::getline(ss, preis, '\n');

        // TODO: throw exception

        speisen.emplace_back(std::stoi(nr), name, std::stof(preis));
    }

    is.close();
}
