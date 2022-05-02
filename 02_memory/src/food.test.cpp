#include <catch2/catch_test_macros.hpp>

#include "food.hpp"

TEST_CASE("food") {
  Food food(42, "test", 12.5);
  REQUIRE(food.getBestellnummer() == 42);
  REQUIRE(food.getBezeichnung() == "test");
  REQUIRE(food.getPreis() == 12.5);

  std::string filename = std::tmpnam(nullptr);
  speichern(filename, {food});

  std::vector<Food> loaded;
  laden(filename, loaded);
  REQUIRE(loaded.size() == 1);
  REQUIRE(loaded[0].getBestellnummer() == 42);
  REQUIRE(loaded[0].getBezeichnung() == "test");
  REQUIRE(loaded[0].getPreis() == 12.5);
}
