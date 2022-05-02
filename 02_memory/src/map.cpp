#include "map.hpp"

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

cppp::Map::Map(const std::size_t size)
    : size(size)
{
    // TODO
}

cppp::Map::~Map()
{
    // TODO
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
    return 0; // TODO
}
