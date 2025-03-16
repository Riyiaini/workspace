#include <iostream>
#include "my_enable_if.h"

using std::cout;
using std::endl;
using my_std::enable_if;

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
    Is_same<int>();
    Is_same<float>();
    return 0;
}