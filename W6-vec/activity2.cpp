#include <vector>
#include <iostream>

void add_to_vec(std::vector<int> vec, int val) {
    vec[0] = val;
}

void add_to_arr(int* vec, int val) {
    vec[0] = val;
}

int main() {
    std::vector<int> vec = {1,2,3,4};
    add_to_vec(vec, 5);
    std::cout << "vec: ";
    for (int val : vec) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;
    // a) works with copy. Fucntion did not change the original vec.
    
    int arr[] = {1,2,3,4};
    add_to_arr(arr, 5);
    std::cout << "arr: ";
    for (int val : arr) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;
    // b) works with original. Function changes the original arr.

    return 0;
}