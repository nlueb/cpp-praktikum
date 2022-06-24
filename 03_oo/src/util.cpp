#include "util.hpp"

#include <iostream>

void readline(std::string& line)
{
    if (!std::getline(std::cin, line)) {
        if (std::cin.eof()) {
            std::cout << "Bye." << std::endl;
            exit(0);
        } else {
            std::cerr << "Somthing went wrong with your input.";
            exit(1);
        }
    }
}
