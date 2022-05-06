#include "food.hpp"
#include "map.hpp"
#include <vector>
#include <iostream>

int main(int argc, char** argv)
{
    std::vector<Food> food_vec;
    laden("../food.csv", food_vec);
    for (Food& food : food_vec) {
        std::cout << food.getCSV();
    }

    return 0;
}
