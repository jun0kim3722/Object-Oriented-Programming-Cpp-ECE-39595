#include <iostream>

#include "hash_list.h"

int trace_1();
int trace_2();
int trace_3();
int trace_4();
int trace_5();

#ifdef PART2 // Only test iterators in part 2
void iterator_example(hash_list &list)
{
    /** We have to reset the iterator before we use it */
    list.reset_iter();

    /** We want to iterate over all nodes, so keep iterating until we're at the end */
    while (!list.iter_at_end())
    {
        /** Get pointers to key/value pairs */
        std::optional<std::pair<const int *, float *>> node_values = list.get_iter_value();

        /** Increment the VALUE. Note that the key remains unchanged */
        (*node_values.value().second)++;

        std::cout << "Key: " << *node_values.value().first
                  << " and value: " << *node_values.value().second << std::endl;

        /** Go to the next element */
        list.increment_iter();
    }
}
#endif

int main(int argc, char *argv[])
{

#ifdef PART1
    hash_list list;
    hash_list list2(list);
    if (list2.get_size() != 0)
    {
        std::cout << "Invalid size" << list2.get_size() << std::endl;
        exit(1);
    }
    if (list2.get_head() != nullptr) {
        std::cout << "Invalid head" << list2.get_head() << std::endl;
    }
    if (list2.get_ptr() != nullptr) {
        std::cout << "Invalid iterptr" << list2.get_ptr() << std::endl;
    }

    hash_list list3 = list;
    if (list3.get_size() != 0)
    {
        std::cout << "Invalid size" << list3.get_size() << std::endl;
        exit(1);
    }
    if (list3.get_head() != nullptr) {
        std::cout << "Invalid head" << list3.get_head() << std::endl;
    }
    if (list3.get_ptr() != nullptr) {
        std::cout << "Invalid iterptr" << list3.get_ptr() << std::endl;
    }
    

    list.insert(1, 1);
    list.insert(2, 4);
    list.insert(3, 5);

    if (list.get_head() == nullptr) {
        std::cout << "Invalid head" << std::endl;
    }
    if (list.get_ptr() != nullptr) {
        std::cout << "Invalid iterptr" << std::endl;
    }

    /** Get pointers to key/value pairs */
    std::optional<std::pair<const int *, float *>> node_values = list.get_iter_value();
    if (node_values.has_value()) {
        std::cout << "Invalid get_iter_value" << list.get_ptr() << std::endl;
    }
    // list.increment_iter();
    list.reset_iter();

    if (!list.get_value(1).has_value())
    {
        std::cout << "expected 1 to be in list2 but it wasn't" << std::endl;
        exit(1);
    }

    if (list.get_ptr() == nullptr) {
        std::cout << "Invalid iterptr" << list.get_ptr() << std::endl;
    }

    node_values = list.get_iter_value();
    if (!node_values.has_value()) {
        std::cout << "Invalid none get_iter_value" << list.get_ptr() << std::endl;
    }
    else {
        std::cout << "get_iter_value" << *node_values.value().first << ", " << *node_values.value().second << std::endl;
    }
    list.increment_iter();

    node_values = list.get_iter_value();
    if (!node_values.has_value()) {
        std::cout << "Invalid none get_iter_value" << list.get_ptr() << std::endl;
    }
    else {
        std::cout << "get_iter_value" << *node_values.value().first << ", " << *node_values.value().second << std::endl;
    }
    list.increment_iter();

    node_values = list.get_iter_value();
    if (!node_values.has_value()) {
        std::cout << "Invalid none get_iter_value" << list.get_ptr() << std::endl;
    }
    else {
        std::cout << "get_iter_value" << *node_values.value().first << ", " << *node_values.value().second << std::endl;
    }
    list.increment_iter();

    node_values = list.get_iter_value();
    if (node_values.has_value()) {
        std::cout << "Invalid get_iter_value" << list.get_ptr() << std::endl;
    }
    if (!list.iter_at_end()) {
        std::cout << "Invalid iter_at_end" << list.get_ptr() << std::endl;
    }

    list.increment_iter();
    if (!list.iter_at_end()) {
        std::cout << "Invalid iter_at_end" << list.get_ptr() << std::endl;
    }




    hash_list list4(list);
    if (list4.get_size() != 3)
    {
        std::cout << "Invalid size" << list4.get_size() << std::endl;
        exit(1);
    }
    if (!list4.get_value(1).has_value())
    {
        std::cout << "expected 1 to be in list4 but it wasn't" << std::endl;
        exit(1);
    }
    if (!list4.get_value(2).has_value())
    {
        std::cout << "expected 2 to be in list4 but it wasn't" << std::endl;
        exit(1);
    }
    if (!list4.get_value(3).has_value())
    {
        std::cout << "expected 3 to be in list4 but it wasn't" << std::endl;
        exit(1);
    }

    // list3 = list;
    // if (list3.get_size() != 3)
    // {
    //     std::cout << "Invalid size" << list3.get_size() << std::endl;
    //     exit(1);
    // }
    // if (!list3.get_value(1).has_value())
    // {
    //     std::cout << "expected 1 to be in list3 but it wasn't" << std::endl;
    //     exit(1);
    // }
    // if (!list3.get_value(2).has_value())
    // {
    //     std::cout << "expected 2 to be in list3 but it wasn't" << std::endl;
    //     exit(1);
    // }
    // if (!list3.get_value(3).has_value())
    // {
    //     std::cout << "expected 3 to be in list3 but it wasn't" << std::endl;
    //     exit(1);
    // }

    // if (!list3.remove(3))
    // {
    //     std::cout << "Failed to remove 3 from list" << std::endl;
    //     exit(1);
    // }
    // if (!list3.remove(2))
    // {
    //     std::cout << "Failed to remove 3 from list" << std::endl;
    //     exit(1);
    // }
    // if (!list3.remove(1))
    // {
    //     std::cout << "Failed to remove 3 from list" << std::endl;
    //     exit(1);
    // }

    // if (list.remove(4))
    // {
    //     std::cout << "Failed to remove 3 from list" << std::endl;
    //     exit(1);
    // }


    // list.insert(5, 5);
    // if (list.get_size() != 3)
    // {
    //     std::cout << "Invalid size" << list.get_size() << std::endl;
    //     exit(1);
    // }

    // list.insert(6, 6);
    // if (list.get_size() != 4)
    // {
    //     std::cout << "Invalid size" << list.get_size() << std::endl;
    //     exit(1);
    // }

    // if (!list.get_value(3).has_value())
    // {
    //     std::cout << "expected 3 to be in list but it wasn't" << std::endl;
    //     exit(1);
    // }

    // if (!list.get_value(4).has_value())
    // {
    //     std::cout << "expected 4 to be in list but it wasn't" << std::endl;
    //     exit(1);
    // }

    // if (!list.get_value(5).has_value())
    // {
    //     std::cout << "expected 5 to be in list but it wasn't" << std::endl;
    //     exit(1);
    // }

    // if (!list.get_value(6).has_value())
    // {
    //     std::cout << "expected 6 to be in list but it wasn't" << std::endl;
    //     exit(1);
    // }

    

    // // if (!list.remove(3))
    // // {
    // //     std::cout << "Failed to remove 3 from list" << std::endl;
    // //     exit(1);
    // // }

    // // if (list.get_value(3).has_value())
    // // {
    // //     std::cout << "Unexpected 3 in list" << std::endl;
    // //     exit(1);
    // // }

    // if (!list.remove(4))
    // {
    //     std::cout << "Failed to remove 4 from list" << std::endl;
    //     exit(1);
    // }

    // if (list.get_value(4).has_value())
    // {
    //     std::cout << "Unexpected 4 in list" << std::endl;
    //     exit(1);
    // }

    // if (list.get_size() != 3)
    // {
    //     std::cout << "Invalid size" << list.get_size() << std::endl;
    //     exit(1);
    // }

    // if (!list.remove(5))
    // {
    //     std::cout << "Failed to remove 5 from list" << std::endl;
    //     exit(1);
    // }

    // if (list.get_value(5).has_value())
    // {
    //     std::cout << "Unexpected 5 in list" << std::endl;
    //     exit(1);
    // }
    // if (list.get_size() != 2)
    // {
    //     std::cout << "Invalid size" << list.get_size() << std::endl;
    //     exit(1);
    // }

    // if (!list.remove(3))
    // {
    //     std::cout << "Failed to remove 5 from list" << std::endl;
    //     exit(1);
    // }
    // if (list.get_value(3).has_value())
    // {
    //     std::cout << "Unexpected 3 in list" << std::endl;
    //     exit(1);
    // }
    // if (list.get_size() != 1)
    // {
    //     std::cout << "Invalid size" << list.get_size() << std::endl;
    //     exit(1);
    // }

    // if (!list.remove(6))
    // {
    //     std::cout << "Failed to remove 6 from list" << std::endl;
    //     exit(1);
    // }
    // if (list.get_value(6).has_value())
    // {
    //     std::cout << "Unexpected 6 in list" << std::endl;
    //     exit(1);
    // }
    // if (list.get_size() != 0)
    // {
    //     std::cout << "Invalid size" << list.get_size() << std::endl;
    //     exit(1);
    // }

    // if (list.remove(6))
    // {
    //     std::cout << "Failed to remove 6 from list" << std::endl;
    //     exit(1);
    // }
    // if (list.get_size() != 0)
    // {
    //     std::cout << "Invalid size" << list.get_size() << std::endl;
    //     exit(1);
    // }


#endif

#ifdef PART2
    iterator_example(list);
#endif

}
