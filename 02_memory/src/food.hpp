#pragma once

#include <string>
#include <vector>

class Food {
    int bestellnr;
    std::string bezeichnung;
    float preis;

public:
    Food() = delete;
    Food(int bestellnummer, std::string bezeichnung, float preis);
    std::string getBezeichnung() const;
    float getPreis() const;
    int getBestellnummer() const;
    std::string getCSV() const;
};

void speichern(const std::string& dateiname, const std::vector<Food>& speisen);
void laden(const std::string& dateiname, std::vector<Food>& speisen);
