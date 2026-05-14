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