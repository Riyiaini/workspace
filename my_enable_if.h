#ifndef MY_ENABLE_IF_H
#define MY_ENABLE_IF_H

namespace my_std {

    template<bool B, typename T = void>
    struct enable_if {};

    template<typename T>
    struct enable_if<true, T> {
        using type = T;
    };
};

#endif // ENABLE_IF_H