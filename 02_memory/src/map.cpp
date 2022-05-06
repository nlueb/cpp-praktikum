#include "map.hpp"

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

cppp::Map::Map(const std::size_t size)
    : size { size }
    , arr { new MapBucket[size] }
{
}

cppp::Map::~Map()
{
    delete[] arr;
}

void cppp::Map::insert(const std::string& key, const std::vector<Item>& order)
{
    // TODO
}

std::vector<cppp::Item> cppp::Map::get(const std::string& key)
{
    return {}; // TODO
}

void cppp::Map::remove(const std::string& key)
{
    // TODO
}

std::size_t cppp::Map::calcHash(const std::string& key)
{
    std::size_t hash = 0;
    for (const char& c : key) {
        hash += static_cast<std::size_t>(c);
    }
    return hash % size;
}
