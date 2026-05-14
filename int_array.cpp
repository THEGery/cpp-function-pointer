#include "int_array.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>

namespace ia {
    // Connect func pointers to func deffinitions
    void connect(IntArray* self) {
        self->destruct = destruct;
        self->pop_back = pop_back;
        self->push_back = push_back;
        self->insert = insert;
        self->count = count;
        self->index = index;
        self->print = print;
        self->size = size;
        self->sum = sum;
        self->add = add;
        self->mul = mul;
    }


    void grow_reserved(IntArray* self) {
        std::size_t new_size = self->__reserved * 2;

        int* new_data = new int[new_size]; // new larger memory slot

        for (std::size_t i = 0; i < self->__elements; i++){
            new_data[i] = self->__array[i]; // migrate data
        }

        delete[] self->__array; // array is under new_data

        // Update struct
        self->__array = new_data;
        self->__reserved = new_size;
    } // allocate more space and migrate data


    IntArray* construct() {
        IntArray* ia = new IntArray;

        ia->__reserved = 100;
        ia->__elements = 0;

        ia->__array = new int[100];
        connect(ia);

        return ia;
    }


    IntArray* construct(std::size_t dimension) {
        IntArray* ia = new IntArray;

        ia->__reserved = dimension;
        ia->__elements = 0;

        ia->__array = new int[dimension];
        connect(ia);

        return ia;
    }


    IntArray* zeros(std::size_t dimension) {
        IntArray* ia = new IntArray;

        ia->__reserved = dimension;
        ia->__elements = dimension;

        ia->__array = new int[dimension]{};
        connect(ia);

        return ia;
    }


    IntArray* ones(std::size_t dimension) {
        IntArray* ia = new IntArray;

        ia->__reserved = dimension;
        ia->__elements = dimension;

        ia->__array = new int[dimension];

        for (std::size_t i = 0; i < dimension; i++) {
            ia->__array[i] = 1;
        }

        connect(ia);

        return ia;
    }


    IntArray* range(int start, int stop) {
        std::size_t dimension = static_cast<std::size_t>(stop - start);

        IntArray* ia = construct(dimension);
        ia->__elements = dimension;

        int current = start;
        for (std::size_t i = 0; i < dimension; ++i) {
            ia->__array[i] = current++;
        }

        return ia;
    }


    IntArray* destruct(IntArray* self) {
        if (self != nullptr) {
            delete[] self->__array;
            self->__array = nullptr;
        }

        delete self;
        return nullptr;
    }


    int pop_back(IntArray* self) {
        std::size_t last = self->__array[self->__elements - 1];

        self->__elements--;

        return last;
    }


    void push_back(IntArray* self, int elem) {
        if (self->__reserved == self->__elements) {
            grow_reserved(self);
        }

        self->__array[self->__elements] = elem;
        self->__elements++;
    }


    void insert(IntArray* self, std::size_t index, int elem) {
        if (self->__reserved == self->__elements) {
            grow_reserved(self);
        }

        for (std::size_t i = self->__elements; i > index; i--) {
            self->__array[i] = self->__array[i - 1];
        }

        self->__array[index] = elem;
        self->__elements++;
    }


    std::size_t count(const IntArray* self, int elem) {
        std::size_t counter = 0;
        for (std::size_t i = 0; i < self->__elements; i++) {
            if (self->__array[i] == elem) {
                counter++;
            }
        }

        return counter;
    }


    int index(const IntArray* self, std::size_t index) {
        if (index > self->__elements) {
            std::cerr << "IndexError: Given index is " << index
                      << " but array only has " << self->__elements 
                      << "elements" << std::endl; 
        }

        return self->__array[index];
    }


    void print(const IntArray* self) {
        for (std::size_t i = 0; i < self->__elements; i++) {
            std::cout << self->__array[i] << " ";
        }

        std::cout << std::endl;
    }


    std::size_t size(const IntArray* self) {
        return self->__elements;
    }


    long int sum(const IntArray* self) {
        int sum = 0;
        for (std::size_t i = 0; i < self->__elements; i++) {
            sum += self->__array[i];
        }

        return sum;
    }


    IntArray* add(const IntArray* first, const IntArray* second) {
        std::size_t length = (first->__elements > second->__elements) 
                      ? first->__elements 
                      : first->__elements;

        IntArray* result = zeros(length);

        for (std::size_t i = 0; i < length; i++) {
            int sum = 0;
            if (i < first->__elements) {
                sum += first->__array[i];
            }
            if (i < second->__elements) {
                sum += second->__array[i];
            }
            result->__array[i] = sum;
        }

        return result;
    }


    IntArray* mul(const IntArray* first, const IntArray* second) {
        std::size_t length = (first->__elements > second->__elements) 
                      ? first->__elements 
                      : first->__elements;

        IntArray* result = zeros(length);

        for (std::size_t i = 0; i < length; i++) {

            if (i < first->__elements && i < second->__elements) {
                result->__array[i] = first->__array[i] * second->__array[i];
            }
            else if (i < first->__elements) {
                result->__array[i] = first->__array[i];
            }
            else {
                result->__array[i] = second->__array[i];
            }
        }

        return result;
    }
}