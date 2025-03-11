#include <vector>
#include <iostream>

void print(std::vector<std::vector<int>> m) {
    std::cout << "Matrix: " << std::endl;
    std::cout << "(";
    for (int i = 0; i < m.size(); i++) {
        std::vector<int> row = m.at(i);
        for (int j = 0; j < row.size(); j++) {
            std::cout << row.at(j);

            if (j != row.size() - 1) {
                std::cout << " ";
            }
        }
        if (i != m.size() - 1) {
            std::cout << std::endl;
        }
    }
    std::cout << ")" << std::endl;
}

int main() {
    std::vector<std::vector<int>> m1;
    m1.push_back({1,2,3});
    m1.push_back({3,4,5});
    print(m1);
    
    std::vector<std::vector<int>> m2;
    m2.push_back({1,2,3,4});
    m2.push_back({5,6,7,8});
    m2.push_back({9,10,11,12});
    print(m2);

    return 0;
}
