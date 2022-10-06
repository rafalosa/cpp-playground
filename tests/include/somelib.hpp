#pragma once

#include <type_traits>

namespace math{
    template<class T,
    class = typename std::enable_if<std::is_arithmetic<T>::value>::type> T  multiply(T arg1, T arg2){

        return arg1 * arg2;

    }
} // namespace math