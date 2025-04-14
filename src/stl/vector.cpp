#include <iostream>
#include <vector>

using namespace std;

void vector_func1() {
    std::vector<int> v = {1, 2, 3};
    v.push_back(4);

    for (auto&& i : v) {
        std::cout << "item= " << i << "\t";
    }
};