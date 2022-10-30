#include "linear_generator.hpp"
#include <iostream>
#include <array>

// Compile time PI estimation.


// Globals
constexpr auto generator  = LinearCongruentialGenerator();

// Points number is restricted due to the maximal depth of constant expression evaluation.
// This can be modified with the -fconstexpr-steps flag.
constexpr std::size_t points_num = 100000;

//Rest
struct Point{
    float x,y;
};

// Compile time point generation.
constexpr auto generate_random_point(int num){

    return Point{generator.random_float(num), generator.random_float(num + 1)};
}

// The circle is assumed to be inscribed in a square with boundaries set on (-1,1) on each axis. This enables one to not calculate the square root
// of the radius which currently (C++20) is not defined as a constant expression and cannot be done at compile time.
constexpr bool in_circle(const Point pt){

    auto r_squared = pt.x*pt.x + pt.y*pt.y;

    return r_squared <= 1;
}

int main(){

    using points_array_t = std::array<Point, points_num>;

    // I tried to do this with std::generate which should be doable since C++20, but I couldn't make it work.
    constexpr auto gathered_points = [](){
        points_array_t pt_array{};
        int points_in_circle = 0;
        for (auto i{0U}; i < points_num; i++) {
            pt_array[i] = generate_random_point(i);
            points_in_circle += static_cast<int>(in_circle(pt_array[i]));
        }
        return points_in_circle;
    }();

    constexpr auto pi = 4 * static_cast<float>(gathered_points) / static_cast<float>(points_num);

    std::cout << pi <<std::endl;

    return 0;
}