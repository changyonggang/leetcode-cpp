#include "vector.h"

void VectorOpt::hello_func1() {
    printf("hello_func1 \n");
};

void vector_f() {
    std::vector<int> v = {1, 2, 3};
    v.push_back(4);

    for (auto&& i : v) {
        std::cout << "item= " << i << "\t";
    }
};