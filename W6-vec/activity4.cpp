#include <vector>
#include <iostream>

void push_back(int val) {
    
}

int main() {
    // 1)
    std::vector<int> vec;
    std::cout << vec.capacity() << " : " << vec.size() << std::endl; // starts with 0 
    for (int i = 1; i < 10; i++) {
        vec.push_back(i);
        std::cout << vec.capacity() << " : " << vec.size() << std::endl;
    }
    // capacity is always 2*n. It grows when push back happens and size == capacity

    // 2)
    for (int i = 1; i < 10; i++) {
        vec.pop_back();
        std::cout << vec.capacity() << " : " << vec.size() << std::endl;
    }
    // capacity stays same even when size is reducing
}