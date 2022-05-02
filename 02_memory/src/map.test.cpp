#include <catch2/catch_test_macros.hpp>

#include "map.hpp"

namespace cppp {
// Normalerweise würden diese Operatoren in map.hpp definiert werden.
// Wir stellen sie für die Tests hier bereit da sie nicht Teil der Aufgabe
// sind und für die Bearbeitung nicht benötigt werden.

bool operator==(const Item &lhs, const Item &rhs) {
  return lhs.anzahl == rhs.anzahl && lhs.bezeichnung == rhs.bezeichnung;
}

std::ostream &operator<<(std::ostream &os, const Item &item) {
  return os << item.anzahl << "x " << item.bezeichnung;
}
} // namespace cppp

TEST_CASE("map") {
  cppp::Map map(16);
  std::vector<cppp::Item> a = {{1, "a"}, {2, "b"}};
  std::vector<cppp::Item> b = {{3, "c"}, {4, "d"}};

  SECTION("empty map") {
    REQUIRE_THROWS_AS(map.get("some_key"), std::invalid_argument);
    REQUIRE_NOTHROW(map.remove("some_other_key"));
  }

  SECTION("different hash") {
    map.insert("a", a);
    map.insert("b", b);
    REQUIRE(map.get("a") == a);
    REQUIRE(map.get("b") == b);
    map.remove("a");
    REQUIRE_THROWS_AS(map.get("a"), std::invalid_argument);
  }

  SECTION("same hash") {
    map.insert("a", a);
    map.insert("q", b);
    REQUIRE(map.get("a") == a);
    REQUIRE(map.get("q") == b);
    map.remove("a");
    REQUIRE_THROWS_AS(map.get("a"), std::invalid_argument);
  }
}
