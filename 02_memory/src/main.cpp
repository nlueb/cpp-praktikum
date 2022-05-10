#include "food.hpp"
#include "map.hpp"

#include <iostream>
#include <vector>

int main()
{
    std::vector<Food> food_vec;

    try {
        laden("food.csv", food_vec);
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    for (Food& food : food_vec) {
        std::cout << food.getCSV();
    }

    return 0;
}
