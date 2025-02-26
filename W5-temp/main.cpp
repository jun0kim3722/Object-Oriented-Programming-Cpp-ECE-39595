#include <iostream>
#include "complex.h"

int minArray(const int *array, int length) {
    int min = array[0];
    for (int i = 1; i < length; i++) {
        if (min > array[i]) {
            min = array[i];
        }
    }

    return min;
}

template<typename T> T minArrayGeneric(const T *array, int length) {
    T min = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    return min;
}

int main() {
    int array1[] = {5,4,1,2,3};
    float array2[] = {6.5,1.5,-2.5,3.5, 0.1};
    std::string array3[] = {"Ric", "I", "Name"};
    Complex array4[] = {{1,1}, {1,2}, {-1,5}, {5,1}};

    std::cout << "test minArray: " << minArray(array1, 5) << std::endl;
    std::cout << "test minArrayG with int: " << minArrayGeneric(array1, 5) << std::endl;
    std::cout << "test minArrayG with float: " << minArrayGeneric(array2, 5) << std::endl;
    std::cout << "test minArrayG with string: " << minArrayGeneric(array3, 3) << std::endl;
    Complex min_val = minArrayGeneric(array4, 4);
    std::cout << "test minArrayG with complex: " << min_val.get_real() << min_val.get_im() << std::endl;
}