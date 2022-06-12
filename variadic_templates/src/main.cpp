#include <iostream>
#include "variadic_templates.tpp"

int main(){

    constexpr int some_const = 10;

    std::cout<<"Displaying mixed type sequence with a single templated function:\n";
    unpacker(3.8, "Argument 2", &some_const, 234567); // Thanks to the parameter pack, types can be mixed and matched.
    std::cout<<"End of sequence\n\n";

    VectorWrapper<int> vec_wrap(1, 2, 3, 4, 5, 6);
    std::cout<<"Elements in vector:\n";
    for(const auto& element: vec_wrap.m_vec){

        std::cout << element << std::endl;

    }
    std::cout<<"End of sequence\n";

    return 0;
}
