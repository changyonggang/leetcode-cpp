#ifndef STL_VECTOR_H
#define STL_VECTOR_H

#include <iostream>
#include <vector>

using namespace std;

void vector_f();

class VectorOpt {
   public:
    void init_function() {
        printf("init_function \n");
        std::vector<int> v = {1, 2, 3};
        v.push_back(4);

        for (auto&& i : v) {
            std::cout << "item= " << i << "\t";
        }



    };
    void hello() { printf("hello \n"); };
    void hello_func1();
};

#endif  // STL_VECTOR_H