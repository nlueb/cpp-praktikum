#include "map.hpp"

#include <algorithm>
#include <iterator>
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
    const std::size_t index = this->calcHash(key);
    MapBucket& bucket = this->arr[index];

    if (bucket.empty()) {
        bucket.push_back({ key, order });
        return;
    }

    // Overwrite if bucket contains key
    for (MapElement& elem : bucket) {
        if (elem.key == key) {
            elem.value.assign(std::begin(order), std::end(order));
            return;
        }
    }

    // Bucket does not contain key so adding it
    bucket.push_back({ key, order });
}

std::vector<cppp::Item> cppp::Map::get(const std::string& key)
{
    const std::size_t index = this->calcHash(key);
    const MapBucket& bucket = this->arr[index];

    for (const MapElement& elem : bucket) {
        if (elem.key == key) {
            return elem.value;
        }
    }

    throw std::invalid_argument("Key not found");
}

void cppp::Map::remove(const std::string& key)
{
    const std::size_t index = this->calcHash(key);
    MapBucket& bucket = this->arr[index];

    bucket.erase(std::remove_if(bucket.begin(),
                                bucket.end(),
                                [&key](const MapElement& m) { return m.key == key; }),
                 bucket.end());
}

std::size_t cppp::Map::calcHash(const std::string& key)
{
    std::size_t hash = 0;
    for (const char& c : key) {
        hash += static_cast<std::size_t>(c);
    }
    return hash % size;
}
