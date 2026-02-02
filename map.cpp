#include "map_operations.h"

void MapOperations::insert(std::map<std::string, int>& map, const std::string& key, int value) {
    map[key] = value;
}

void MapOperations::remove(std::map<std::string, int>& map, const std::string& key) {
    map.erase(key);
}

bool MapOperations::contains(const std::map<std::string, int>& map, const std::string& key) {
    return map.find(key) != map.end();
}

int MapOperations::getValue(const std::map<std::string, int>& map, const std::string& key) {
    auto it = map.find(key);
    if (it != map.end()) {
        return it->second;
    }
    throw std::out_of_range("Key not found in map");
}

size_t MapOperations::countElements(const std::map<std::string, int>& map) {
    return map.size();
}