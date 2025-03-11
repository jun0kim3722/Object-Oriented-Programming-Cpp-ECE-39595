#include <vector>

int main() {
    std::vector<int> vec = {1, 2};

    int el1 = vec[2];
    // works without any error. valgrind memory error.

    int el2 = vec.at(2);
    // terminate called after throwing an instance of 'std::out_of_range'
    // what():  vector::_M_range_check: __n (which is 2) >= this->size() (which is 2)
    // Aborted (core dumped)
    // No valgrind error

    return 0;
}