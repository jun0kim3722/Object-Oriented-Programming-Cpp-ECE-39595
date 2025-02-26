#include <iostream>
#include <algorithm> 
#include "hash_map.h"


int main() {
    // test hash_list
    // using K = std::string;
    // using V = double;
    // std::pair<K,V> insert_list[] = {{"my", 0.4}, {"name", 89}, {"is", 8.1}, {"Ric", 3.333333}};
    // size_t insert_len = sizeof(insert_list) / sizeof(insert_list[0]);
    // hash_list<K, V> list1;

    // std::cout << "List1 insert test" << std::endl;
    // for (size_t i=0; i < insert_len; i++) {
    //     list1.insert(insert_list[i].first, insert_list[i].second);

    //     if (!list1.get_value(insert_list[i].first).has_value())
    //     {
    //         std::cout << "get value error: " << i << std::endl;
    //     }
    //     if (list1.get_size() != i+1)
    //     {
    //         std::cout << "Invalid size: " << i << list1.get_size() << std::endl;
    //     }
    // }

    // std::cout << "List2 copy test" << std::endl;
    // hash_list<K, V> list2(list1);
    // for (size_t i=0; i < insert_len; i++) {
    //     if (!list2.get_value(insert_list[i].first).has_value())
    //     {
    //         std::cout << "get value error: " << i << std::endl;
    //     }
    //     if (list2.get_size() != insert_len)
    //     {
    //         std::cout << "Invalid size: " << list2.get_size() << std::endl;
    //     }
    // }

    // std::cout << "List3 copy oper test" << std::endl;
    // hash_list<K, V> list3 = list1;
    // for (size_t i=0; i < insert_len; i++) {
    //     if (!list3.get_value(insert_list[i].first).has_value())
    //     {
    //         std::cout << "get value error: " << i << std::endl;
    //     }
    //     if (list3.get_size() != insert_len)
    //     {
    //         std::cout << "Invalid size: " << list3.get_size() << std::endl;
    //     }
    // }

    // std::cout << "List1 remove test" << std::endl;
    // for (size_t i=0; i < insert_len; i++) {
    //     list1.remove(insert_list[i].first);

    //     if (list1.get_value(insert_list[i].first).has_value())
    //     {
    //         std::cout << "get value error: " << i << std::endl;
    //     }
    //     if (list1.get_size() != insert_len-i-1)
    //     {
    //         std::cout << "Invalid size: " << i << list1.get_size() << std::endl;
    //     }
    // }

    // std::cout << "List2 iter test" << std::endl;
    // list2.reset_iter();
    // for (size_t i=0; i < insert_len; i++) {
    //     if (list2.iter_at_end()) {
    //         std::cout << "Invalid iter_at_end" << std::endl;
    //     }

    //     std::optional<std::pair<const K*, V*>> node_values = list2.get_iter_value();

    //     if (!node_values.has_value()) {
    //         std::cout << "Invalid get_iter_value" << std::endl;
    //     }
    //     else {
    //         std::cout << *node_values->first << " : " << *node_values->second << std::endl;
    //     }

    //     list2.increment_iter();
    // }
    // if (!list2.iter_at_end()) {
    //     std::cout << "Invalid iter_at_end" << std::endl;
    // }

    // test hash_map
    
    // rehash check
    size_t size = 3000;
    size_t capacity = 300;
    // 209, 1021, 2039
    float upper_load_factor = 1;
    float lower_load_factor = 0.2;
    hash_map<float,float> map(capacity, upper_load_factor, lower_load_factor);
    hash_map<float,float> map_ = map;

    std::cout << "----Insert Capacity check" << std::endl;
    for (size_t i = 1; i <= size; i++) {
        // std::cout << "-------------------insert : " << i<<std::endl;
        map.insert(i, i);

        size_t map_size = map.get_size();
        if (map_size != i) {
            std::cout << "Wrong get size" << map_size << std::endl;
        }

        size_t map_capacity = map.get_capacity();
        if (map_capacity != capacity) {
            std::cout << "Capacity Update: " << map_capacity << " at " << i;
            bool is_upper_bound = map_size < upper_load_factor * map_capacity;
            if (!is_upper_bound) {
                std::cout << " Wrong resized capacity" << map_size << is_upper_bound;
            }
            capacity = map_capacity;

            std::cout << std::endl;

            for (size_t j = 1; j <= i; j++) {
                if (!map.get_value(j).has_value())
                {
                    std::cout << "expected to be in but it wasn't" << std::endl;
                }
            }
        }
    }
    size_t map_size = map.get_size();
    if (map_size != size) {
        std::cout << "Wrong get size" << map_size << std::endl;
    }
    size_t map_capacity_top = map.get_capacity();
    std::cout << map_capacity_top << std::endl;



    std::cout << "----Insert Capacity check copy" << std::endl;
    for (size_t i = 1; i <= size; i++) {
        map_.insert(i, i);

        size_t map_size = map_.get_size();
        if (map_size != i) {
            std::cout << "Wrong get size" << map_size << std::endl;
        }

        size_t map_capacity = map_.get_capacity();
        if (map_capacity != capacity) {
            std::cout << "Capacity Update: " << map_capacity << " at " << i;
            bool is_upper_bound = map_size < upper_load_factor * map_capacity;
            if (!is_upper_bound) {
                std::cout << " Wrong resized capacity" << map_size << is_upper_bound;
            }
            capacity = map_capacity;

            std::cout << std::endl;

            for (size_t j = 1; j <= i; j++) {
                if (!map_.get_value(j).has_value())
                {
                    std::cout << "expected to be in but it wasn't" << std::endl;
                }
            }
        }
    }
    map_size = map_.get_size();
    if (map_size != size) {
        std::cout << "Wrong get size" << map_size << std::endl;
    }
    map_capacity_top = map_.get_capacity();
    std::cout << map_capacity_top << std::endl;

    float *sorted_keys_copy = new float[size];
    map_.get_all_sorted_keys(sorted_keys_copy);
    for (size_t i = 1; i <= size; i++) {
        if (sorted_keys_copy[i-1] != i) {
            std::cout << "Sorted Key Error: " << sorted_keys_copy[i-1] << " : " << i << std::endl;
        }
    }
    delete [] sorted_keys_copy;


    hash_map<float,float> map_copy = map;
    map_size = map.get_size();
    size_t copy_map_size = map_copy.get_size();
    if (map_size != copy_map_size) {
        std::cout << "Wrong get size at copy" << map_size << std::endl;
    }
    size_t map_capacity_copy = map.get_capacity();
    if (map_capacity_copy != map_capacity_top) {
        std::cout << "Wrong get capacity at copy" << map_capacity_top << std::endl;
    }

    for (size_t i = 1; i <= size; i++) {
        if (!map_copy.get_value(i).has_value())
        {
            std::cout << "expected to be in but it wasn't" << std::endl;
        }
    }


    hash_map<float,float> map_copy2 = map = map_;
    map_size = map.get_size();
    copy_map_size = map_copy2.get_size();
    if (map_size != copy_map_size) {
        std::cout << "Wrong get size at copy" << map_size << std::endl;
    }
    map_capacity_copy = map.get_capacity();
    if (map_capacity_copy != map_capacity_top) {
        std::cout << "Wrong get capacity at copy" << map_capacity_top << std::endl;
    }

    for (size_t i = 1; i <= size; i++) {
        if (!map_copy2.get_value(i).has_value())
        {
            std::cout << "expected to be in but it wasn't" << std::endl;
        }
    }


    std::cout << "----Remove Capacity check" << std::endl;
    for (size_t i = size; i > 0; i--) {
        if (!map.remove(i)) {
            std::cout << "Wrong remove" << map_size << std::endl;
        }

        size_t map_size = map.get_size();
        if (map_size != i-1) {
            std::cout << "Wrong get size" << map_size << std::endl;
        }

        size_t map_capacity = map.get_capacity();
        if (map_capacity != capacity) {
            std::cout << "Capacity Update: " << map_capacity << " at " << i-1;
            bool is_lower_bound = map_size >= lower_load_factor * map_capacity;
            if (!is_lower_bound) {
                std::cout << " Wrong resized capacity" << map_size << is_lower_bound;
            }
            capacity = map_capacity;

            std::cout << std::endl;
        }
    }

    for (size_t i = size; i > 0; i--) {
        if (!map_.remove(i)) {
            std::cout << "Wrong remove" << map_size << std::endl;
        }

        size_t map_size = map_.get_size();
        if (map_size != i-1) {
            std::cout << "Wrong get size" << map_size << std::endl;
        }

        size_t map_capacity = map_.get_capacity();
        if (map_capacity != capacity) {
            std::cout << "Capacity Update: " << map_capacity << " at " << i-1;
            bool is_lower_bound = map_size >= lower_load_factor * map_capacity;
            if (!is_lower_bound) {
                std::cout << " Wrong resized capacity" << map_size << is_lower_bound;
            }
            capacity = map_capacity;

            std::cout << std::endl;
        }
    }

    // std::cout << "Key size: " << map_.get_size() << std::endl;
    // sorted_keys_copy = new float[size];
    // map_.get_all_sorted_keys(sorted_keys_copy);
    // // for (size_t i = 1; i <= size; i++) {
    // //     std::cout << sorted_keys_copy[i-1] << std::endl;
    // //     if (sorted_keys_copy[i-1] != i) {
    // //         std::cout << "Sorted Key Error: " << sorted_keys_copy[i-1] << " : " << i << std::endl;
    // //     }
    // // }
    // size_t len = sizeof(sorted_keys_copy) / sizeof(sorted_keys_copy[0]);
    // std::cout << "Sorted Key len: " << len << std::endl;
    // delete [] sorted_keys_copy;

    map_size = map.get_size();
    if (map_size != 0) {
        std::cout << "Wrong get size" << map_size << std::endl;
    }
    size_t map_capacity = map.get_capacity();
    std::cout << map_capacity << std::endl;

    if (map.remove(4)) {
        std::cout << "Wrong remove" << map_size << std::endl;
    }
    
    
    // template test
    using K = std::string;
    using V = float;
    std::pair<K,V> insert_list[] = {{"my", 0.4}, {"name", 89}, {"is", 8.1}, {"ric", 3.333333}};

    // using K = int;
    // using V = float;
    // std::pair<K,V> insert_list[] = {{10, 0.4}, {90, 89}, {2, 8.1}, {99, 3.333333}};


    capacity = 3;
    hash_map<K,V> map1(capacity, 100, 0);
    size = sizeof(insert_list) / sizeof(insert_list[0]);

    for (size_t i = 0; i < size; i++) {
        map1.insert(insert_list[i].first, insert_list[i].second);
        
        size_t map1_size = map1.get_size();
        if (map1_size != i + 1) {
            std::cout << "Wrong get size" << map1_size << std::endl;
        }

        if (!map1.get_value(insert_list[i].first).has_value())
        {
            std::cout << "expected to be in but it wasn't" << std::endl;
        }
    }
    hash_map<K,V> map2(map1);
    hash_map<K,V> map3 = map1;

    // get all keys check-----------------------------------------------------
    K *keys = new K[size];
    map1.get_all_keys(keys);
    for (size_t i = 0; i < size; i++) {
        std::cout << "Key: " << keys[i] << std::endl;
    }
    delete [] keys;

    std::sort(insert_list, insert_list + size);
    K *sorted_keys = new K[size];
    map1.get_all_sorted_keys(sorted_keys);
    for (size_t i = 0; i < size; i++) {
        if (sorted_keys[i] != insert_list[i].first) {
            std::cout << "Sorted Key Error: " << sorted_keys[i] << std::endl;
        }
    }
    delete [] sorted_keys;


    // get bucket size check-----------------------------------------------------
    size_t new_capacity = map1.get_capacity();
    size_t *buckets = new size_t[new_capacity];
    map1.get_bucket_sizes(buckets);
    for (size_t i = 0; i < new_capacity; i++) {
        std::cout << "bucket: " << buckets[i] << std::endl;
    }
    delete [] buckets;

    // remove check-----------------------------------------------------
    for (size_t i = 0; i < size; i++) {
        if (!map1.remove(insert_list[i].first))
        {
            std::cout << "Failed to remove from list" << std::endl;
            exit(1);
        }
    }
    if (map1.get_size() != 0) {
        std::cout << "Wrong get size" << map1.get_size() << std::endl;
    }
}