#pragma once

#include <cstdint>

// Compile time version of std::isdigit
consteval static bool comp_isdigit(const char character){

    return character <= '9' && character >= '0';

}

// Compile time version of std::stoi
consteval static int comp_stoi(const char* current_char, int val = 0){

    if(*current_char){

        if(comp_isdigit(*current_char)){

            return comp_stoi(current_char+1, (*current_char - '0') + val * 10); 
        }
    }
    return val;
}

// Compile time seed generation using __TIME__ macro.
consteval static int seed_gen(){

    auto hours = comp_stoi(__TIME__);
    auto mins = comp_stoi(__TIME__ + 3);
    auto sec = comp_stoi(__TIME__ + 6);

    return 3600*hours + 60*mins + sec;

}

// Compile time pseudo random number generation.
class LinearCongruentialGenerator{

    private:

    int modulus{0};
    int multiplier{0};
    int increment{0};

    public:

    constexpr LinearCongruentialGenerator(int modulus = 0x7FFFFFFF, int multiplier = 48271, int increment=0): modulus(modulus), multiplier(multiplier), increment(increment){};
    constexpr uint32_t rec_rng(int num) const{ return (increment + multiplier * ((num > 0) ? rec_rng(num - 1) : seed_gen())) & modulus; }
    constexpr float random_float(int num) const{
        auto temp = rec_rng(num + 1);
        return static_cast<float>(temp) / static_cast<float>(modulus) * 2.0 - 1.0;
    }
    
};