#pragma once

#include <iterator>

template<std::size_t N>
struct Loop{

    template<class Callable>
    Loop(Callable&& func){

        func();
        Loop<N-1>(std::forward<Callable>(func));
    }
};

template<>
struct Loop<0>{

    template<class Callable>
    Loop(Callable&& func){} // Do nothig, this is the (N+1)-th call
};