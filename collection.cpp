#include "collection_operations.h"

void CollectionOperations::addElement(std::vector<int>& collection, int element) {
    collection.push_back(element);
}

void CollectionOperations::removeElement(std::vector<int>& collection, int element) {
    auto it = std::find(collection.begin(), collection.end(), element);
    if (it != collection.end()) {
        collection.erase(it);
    }
}

bool CollectionOperations::containsElement(const std::vector<int>& collection, int element) {
    return std::find(collection.begin(), collection.end(), element) != collection.end();
}

size_t CollectionOperations::getSize(const std::vector<int>& collection) {
    return collection.size();
}

void CollectionOperations::clearCollection(std::vector<int>& collection) {
    collection.clear();
}