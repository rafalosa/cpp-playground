#pragma once

#include <type_traits>

namespace math{
    template<class T, class Q,
    class = typename std::enable_if<std::is_arithmetic<T>::value>::type,
    class = typename std::enable_if<std::is_arithmetic<Q>::value>::type>
    auto  multiply(T arg1, Q arg2){

        return arg1 * arg2;

    }
} // namespace math