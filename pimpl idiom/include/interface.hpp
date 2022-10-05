#pragma once

#include <string_view>

class Animal{

    public:
    // Interface exposed to the user via this header file.
    void makeSound() const;
    int getAge() const;
    std::string_view getName() const;

    Animal(std::string_view name, int age, std::string_view sound);
    ~Animal();

    private:
    // Struct of the implementation, and a pointer to it as a class member. Smart pointer can be used as well.
    struct Implementation;
    Implementation* pimpl;

    // Notice that there are no member variables contained inside this file.

};