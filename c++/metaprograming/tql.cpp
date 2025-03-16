#include <iostream>
#include <type_traits>
#include "my_enable_if.h"
using S = int;
using cl_ref = const S&;
using cl_ptr = const S*;
template<typename tp, size_t col, size_t row>
using cl_ref2d = const tp(&)[col][row];
template<typename tp, size_t col, size_t row>
using cl_ptr2d = const tp(*)[col][row];

using my_std::enable_if;

template<typename T>
struct ConvertToPointer {
    using type = typename std::add_pointer<typename std::remove_reference<T>::type>::type;
};

template<typename T>
constexpr typename ConvertToPointer<T>::type convert_ptr(T&& t) {
    return &t;
}

template<typename T>
struct ConvertToReference {
    using type = typename std::add_lvalue_reference<typename std::remove_pointer<T>::type>::type;
};

template<typename T>
constexpr typename ConvertToReference<T>::type convert_ref(T* t) {
    return *t;
}

int map[5][5] = {1, 2, 3, 4, 6,
                3, 4, 5, 23, 6,
                2, 5, 5, 2, 5,
                4, 7, 1, 8, 3,
                4, 6, 1, 8, 2};

template<typename T>
typename enable_if<std::is_same<T, float>::value, void>::type
Is_same() {
    std::cout << "Is same as float" << std::endl;
}

template<typename T>
typename enable_if<!std::is_same<T, float>::value, void>::type
Is_same() {
    std::cout << "Is not same as float" << std::endl;
}

int main() {

    constexpr bool is_same = std::is_same<ConvertToPointer<cl_ref2d<int, 5, 5>>::type, cl_ptr2d<int, 5, 5>>::value;
    if constexpr (is_same) {
        std::cout << "ConvertToPointer<cl_ref2d<int, 5, 5>>::type is the same as cl_ptr2d<int, 5, 5>" << std::endl;
    } else {
        std::cout << "ConvertToPointer<cl_ref2d<int, 5, 5>>::type is NOT the same as cl_ptr2d<int, 5, 5>" << std::endl;
    }

    
    cl_ref2d<int, 5, 5> ref2 = map;
    cl_ptr2d<int, 5, 5> ptr2 = &map;

    Is_same<float>();
    Is_same<int>();

    std::cout << "ref2[0][0]: " << ref2[0][0] << std::endl;
    std::cout << "ptr2[0][0]: " << (*ptr2)[0][0] << std::endl;

    auto ref2_ptr = convert_ptr(ref2);
    auto ptr2_ref = convert_ref(ptr2);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            std::cout << "ref2_ptr[" << i << "][" << j << "]:" << (*ref2_ptr)[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            std::cout << "ptr2_ref[" << i << "][" << j << "]:" << ptr2_ref[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}