#include <iostream>
#include "hash_map.h"

int main() {
    size_t capacity = 3;
    hash_map map1(capacity);
    size_t size = 10;
    for (size_t i = 1; i <= size; i++) {
        map1.insert(i,i);
        size_t map1_size = map1.get_size();
        if (map1_size != i) {
            std::cout << "Wrong get size" << map1_size << std::endl;
        }
    }
    hash_map map2(map1);
    hash_map map3 = map1;

    // check get capacity-------------------------------------------------------
    if (map1.get_capacity() != capacity) {
        std::cout << "Wrong get capacity" << map1.get_capacity() << std::endl;
    }

    if (map2.get_capacity() != capacity) {
        std::cout << "Wrong get capacity" << map1.get_capacity() << std::endl;
    }

    if (map3.get_capacity() != capacity) {
        std::cout << "Wrong get capacity" << map1.get_capacity() << std::endl;
    }

    // check get value-------------------------------------------------------
    for (size_t i = 1; i <= size; i++) {
        if (!map1.get_value(i).has_value())
        {
            std::cout << "expected to be in but it wasn't" << std::endl;
        }
    }
    if (map1.get_value(size+1).has_value())
    {
        std::cout << "Not expected to be in" << std::endl;
    }

    for (size_t i = 1; i <= size; i++) {
        if (!map2.get_value(i).has_value())
        {
            std::cout << "expected to be in but it wasn't" << std::endl;
        }
    }
    if (map2.get_value(size+1).has_value())
    {
        std::cout << "Not expected to be in" << std::endl;
    }

    for (size_t i = 1; i <= size; i++) {
        if (!map3.get_value(i).has_value())
        {
            std::cout << "expected 1 to be in but it wasn't" << std::endl;
        }
    }
    if (map3.get_value(size+1).has_value())
    {
        std::cout << "Not expected to be in" << std::endl;
    }

    // get size check-----------------------------------------------------
    size_t map1_size = map1.get_size();
    if (map1_size != size) {
        std::cout << "Wrong get size" << map1_size << std::endl;
    }

    // get all keys check-----------------------------------------------------
    int *keys = new int[map1_size];
    map1.get_all_keys(keys);
    for (size_t i = 0; i < size; i++) {
        std::cout << "Key: " << keys[i] << std::endl;
    }

    // get bucket size check-----------------------------------------------------
    size_t *buckets = new size_t[capacity];
    map1.get_bucket_sizes(buckets);
    for (size_t i = 0; i < capacity; i++) {
        std::cout << "bucket: " << buckets[i] << std::endl;
    }

    // remove check-----------------------------------------------------
    for (size_t i = 1; i <= size; i++) {
        if (!map1.remove(i))
        {
            std::cout << "Failed to remove from list" << std::endl;
            exit(1);
        }
    }

    // get size check-----------------------------------------------------
    if (map1.get_size() != 0) {
        std::cout << "Wrong get size" << map1.get_size() << std::endl;
    }
}