#include "int_array.hpp"
#include <cstddef>


namespace ia {
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

        ia->__array = new int[dimension]{};

        return 0;
    }


    IntArray* zeros(std::size_t dimension) {
        IntArray* ia = new IntArray;

        ia->__reserved = dimension;
        ia->__elements = dimension;

        ia->__array = new int[dimension];

        for (std::size_t i = 0; i < dimension; i++) {
            ia->__array[i] = 0;
        }

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

        return 0;
    }


    IntArray* destruct(IntArray* self) {
        return 0;
    }


    int pop_back(IntArray* self) {
        return 0;
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