#pragma once
#include <cstddef>
#include <initializer_list>

class forward_list
{
    public:
        struct Node {
            int val{};
            Node* next{};
        };

    private:
        Node* head{};

    public:
        using size_type = std::size_t;

        //member functions
        ~forward_list() noexcept;        
        

        //element access
        int& front();

        //capacity
        bool empty() const noexcept;

        //modifiers
        void clear() noexcept;
        Node* insert_after(Node* pos, const int val);
        Node* insert_after(Node* pos, size_type count, const int val);
        Node* insert_after(Node* pos, std::initializer_list<int> ilist);
        Node* erase_after(Node* pos);
        Node* erase_after(Node* first, const Node* last);
        void push_front(const int val);
        void pop_front();
        void resize(size_type count, const int val = 0);
        void swap(forward_list& other) noexcept;
};
