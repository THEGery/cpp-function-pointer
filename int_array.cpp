#include "int_array.hpp"
#include <cstddef>


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


    IntArray* construct() {
        IntArray* ia = new IntArray;

        ia->__reserved = 100;
        ia->__elements = 0;

        ia->__array = new int[100];

        return 0;
    }


    IntArray* construct(std::size_t dimension) {
        IntArray* ia = new IntArray;

        ia->__reserved = dimension;
        ia->__elements = dimension;

        ia->__array = new int[dimension];

        return 0;
    }


    IntArray* zeros(std::size_t dimension) {
        IntArray* ia = new IntArray;

        ia->__reserved = dimension;
        ia->__elements = dimension;

        ia->__array = new int[dimension]{};

        return 0;
    }


    IntArray* ones(std::size_t dimension) {
        IntArray* ia = new IntArray;

        ia->__reserved = dimension;
        ia->__elements = dimension;

        ia->__array = new int[dimension];

        for (std::size_t i = 0; i < dimension; i++) {
            ia->__array[i] = 1;
        }

        return 0;
    }


    IntArray* range(int start, int stop) {
        std::size_t dimension = static_cast<std::size_t>(start + (stop - 1));

        IntArray* ia = construct(dimension);

        int count = start;
        for (std::size_t i = 0; i < dimension; ++i) {
            ia->__array[i] = count++;
        }

        return ia;
    }


    IntArray* destruct(IntArray* self) {
        if (self != nullptr) {
            delete[] self->__array;
            delete self;
        }

        connect(self);

        return nullptr;
    }


    int pop_back(IntArray* self) {
        std::size_t last = self->__array[self->__elements - 1];

        self->__elements--;

        return last;
    }


    void push_back(IntArray* self, int elem) {}


    void insert(IntArray* self, std::size_t index, int elem) {}


    std::size_t count(const IntArray* self, int elem) {
        return 0;
    }


    int index(const IntArray* self, std::size_t index) {
        return 0;
    }


    void print(const IntArray* self) {}


    std::size_t size(const IntArray* self) {
        return 0;
    }


    long int sum(const IntArray* self) {
        return 0;
    }


    IntArray* add(const IntArray* first, const IntArray* second) {
        return 0;
    }


    IntArray* mul(const IntArray* first, const IntArray* second) {
        return 0;
    }


}