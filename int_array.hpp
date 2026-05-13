#ifndef INT_ARRAY_HPP
#define INT_ARRAY_HPP

#include <cstddef>


namespace ia {
    struct IntArray;

    struct IntArray {
        std::size_t __reserved;
        std::size_t __elements;
        int* __array;

        IntArray* (*destruct)(IntArray*);
        int (*pop_back)(IntArray*);
        void (*push_back)(IntArray*, int);
        void (*insert)(IntArray*, std::size_t, int);
        std::size_t (*count)(const IntArray*, int);
        int (*index)(const IntArray*, std::size_t);
        void (*print)(const IntArray*);
        std::size_t (*size)(const IntArray*);
        long int (*sum)(const IntArray*);
        IntArray* (*add)(const IntArray*, const IntArray*);
        IntArray* (*mul)(const IntArray*, const IntArray*);
    };

    // Function declerations
    IntArray* construct();
    IntArray* construct(std::size_t dimension);
    IntArray* zeros(std::size_t dimension);
    IntArray* ones(std::size_t dimension);
    IntArray* range(int start, int stop);
    IntArray* destruct(IntArray* self);
    int pop_back(IntArray* self);
    void push_back(IntArray* self, int elem);
    void insert(IntArray* self, std::size_t index, int elem);
    std::size_t count(const IntArray* self, int elem);
    int index(const IntArray* self, std::size_t index);
    void print(const IntArray* self);
    std::size_t size(const IntArray* self);
    long int sum(const IntArray* self);
    IntArray* add(const IntArray* first, const IntArray* second);
    IntArray* mul(const IntArray* first, const IntArray* second);
}
#endif