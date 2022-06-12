#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

template<class... Args> // Initial call with all wanted parameters.
inline void unpacker(Args&& ...instances){

    unpacker(std::forward<Args>(instances)...);
}

template<class Arg, class... Args> // Each next consecutive call, which shrinks the argument list by 1.
inline void unpacker(Arg&& instance, Args&& ...rest){

    std::cout << instance << std::endl; // Unpack first value from pack.
    unpacker(std::forward<Args>(rest)...); // Pass the rest of the parameters to the next function.
}

template<>// Final call.
inline void unpacker(){}


// Templated class with a variadic template constructor.
template<class VectorType>
struct VectorWrapper{

    std::vector<VectorType> m_vec;

    template<class Arg, class... Args>
    VectorWrapper(Arg&& element, Args&&... elements): VectorWrapper(std::forward<Args>(elements)...){

        m_vec.insert(m_vec.begin(), std::forward<Arg>(element));
    }

    VectorWrapper() = default;

    void siema(){}
};
