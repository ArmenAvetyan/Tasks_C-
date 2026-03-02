#pragma once
#include <iostream>
#include <memory>

class vector {
    private:
        size_t m_size {};
        size_t m_capacity {};
        std::unique_ptr<int[]> m_ptr;
        inline auto m_alloc();
        void m_resize(size_t count, int val);

    public:
        void clear();
        size_t insert(size_t, int val);
        size_t insert(size_t pos, size_t count, int val);
        size_t insert(size_t pos, std::initializer_list<int> ilist);
        size_t erase(size_t pos);
        size_t erase(size_t first, size_t last);
        void push_back(int val);
        void pop_back();
        void resize(size_t count);
        void resize(size_t count, int val);
        void swap(vector& other);
        void print();
};
