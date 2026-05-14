#include "int_array.hpp"
#include <iostream>


void print_edited(const std::string_view name, const ia::IntArray* ia, 
                  bool full_size=false);


int main() {
    // TODO: Add print and clean-up for all functions.
    ia::IntArray* ia_ptr = ia::zeros(10);
    print_edited("construct", ia_ptr);
    ia_ptr = ia_ptr->destruct(ia_ptr);


    ia_ptr = ia::ones(10);
    print_edited("ones", ia_ptr);
    ia_ptr = ia_ptr->destruct(ia_ptr);

    return 0;
}


void print_edited(const std::string_view name, const ia::IntArray* ia, 
                  bool full_size) {
    using namespace std;
    std::size_t measure;

    if (full_size) {
        measure = ia->__reserved;
    }
    else {
        measure = ia->__elements;
    }

    cout << name << ": {";
    for (std::size_t i = 0; i < measure; i++) {
        if (i + 1 == measure) {
            cout << ia->__array[i] << "";
        }
        else {
            cout << ia->__array[i] << ", ";
        }
    }
    cout << "}" << endl << endl;
}