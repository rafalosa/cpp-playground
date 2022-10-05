#include "interface.hpp"
#include <iostream>
#include <string_view>

struct Animal::Implementation{

    std::string_view m_name;
    std::string_view m_sound;
    int m_age;

    Implementation(std::string_view name, int age, std::string_view sound): m_name(name), m_age(age), m_sound(sound) {}

};

Animal::Animal(std::string_view name, int age, std::string_view sound){

    pimpl = new Implementation(name, age, sound);

}

Animal::~Animal(){

    delete pimpl;

}

int Animal::getAge() const{

    return pimpl->m_age;

}

void Animal::makeSound() const{

    std::cout << pimpl->m_sound << std::endl;

}

std::string_view Animal::getName() const{

    return pimpl->m_name;

}