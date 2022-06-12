#include <iostream>
#include "recursive_templates.tpp"

int main(){

    int i = 0;
    std::cout << "Variable before looping: i=" << i << std::endl;

    Loop<10>([&]{i++;}); // Execute the passed lambda 10 times

    std::cout << "Variable after looping: i=" << i << std::endl;

    return 0;
}
