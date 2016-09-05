#include "AGSortedList.h"

AGSorted_Elemets::AGSorted_Elemets()
{
    capacity_ = 1024 * 10;
    ints_ = new int64_t[capacity_];
    curr_idx_ = 0;
}

AGSorted_Elemets::~AGSorted_Elemets()
{
    delete[] ints_;
}

void AGSorted_Elemets::increase_capacity()
{
    uint64_t new_capacity = capacity_ * 2;
    int64_t* new_ints = new int64_t[new_capacity];
    for (uint64_t idx = 0; idx < capacity_; ++idx)
    {
        new_ints[idx] = ints_[idx];
    }

    delete[] ints_;
    ints_ = new_ints;
    capacity_ = new_capacity;
}

int64_t* AGSorted_Elemets::get_insert_position(int64_t* old_idx, int64_t value)
{
    int64_t* start = nullptr;
    uint64_t  count = 0;
    uint64_t step = 0;
    count = &ints_[curr_idx_] - old_idx;

    while (count > 0) {
        start = old_idx;
        step = count / 2;
        start += step;
        if (*start < value) {
            old_idx = ++start;
            count -= step + 1;
        }
        else
            count = step;
    }
    return old_idx;
}

void AGSorted_Elemets::print()
{
    for (uint32_t idx = 0; idx < curr_idx_; ++idx)
    {
        std::cout << ints_[idx] << " ";
    }
    std::cout << std::endl;
}

uint64_t AGSorted_Elemets::insert(int64_t value, uint64_t lastIndex)
{
    if (curr_idx_ == capacity_)
    {
        increase_capacity();
    }

    int64_t* place = get_insert_position(&ints_[lastIndex], value);
    if (place == &ints_[curr_idx_])
    {
        ints_[curr_idx_++] = value;
    }
    else
    {
        if (*place != value)
        {
            uint64_t elementstoMove = &ints_[curr_idx_] - place;

            for (uint64_t idx = 0; idx < elementstoMove; ++idx)
            {
                ints_[curr_idx_ - idx] = ints_[curr_idx_ - idx - 1];
            }

            *place = value;
            ++curr_idx_;
        }
    }

    return (place - &ints_[0]);
}