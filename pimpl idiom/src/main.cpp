#include <iostream>

#include "interface.hpp"

// Thanks to the pimpl idiom the pimpl make target which consists of this (main.cpp) file does not need to be recompiled upon making changes to the animal.cpp file.
// The program only needs to be relinked with the newly compiled version of the implementation.

int main(){

    auto obj = Animal("Rupert", 20, "Meow");

    obj.makeSound();

    return 0;
}
