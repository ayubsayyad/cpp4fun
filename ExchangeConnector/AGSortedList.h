//
// Created by ayub on 10/31/15.
//
#ifndef AGSORTED_ELEMETS_INCLUDE
#define AGSORTED_ELEMETS_INCLUDE

#include <cstdint>
#include <iostream>

//template <typename uint64_t SIZE = 1024 * 10>
class  AGSorted_Elemets
{
    public:
        AGSorted_Elemets();
        ~AGSorted_Elemets();
        void print();
        void increase_capacity();
        int64_t* get_insert_position(int64_t* old_idx, int64_t value);
        uint64_t insert(int64_t value, uint64_t lastIndex);

    private:
        uint64_t capacity_;
        int64_t* ints_;
        uint64_t curr_idx_;
};

#endif

