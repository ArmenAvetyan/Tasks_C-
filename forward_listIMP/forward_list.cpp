#include "forward_list.hpp"
#include <stdexcept>

using Node = forward_list::Node;
//member functions

forward_list::~forward_list() noexcept
{
    clear();
}

//element access
int& forward_list::front()
{
    if (!head) throw std::out_of_range("forward_list is empty");
    return head->val;
}

//capacity
bool forward_list::empty() const noexcept
{
    return head == nullptr;
}

//modifiers
void forward_list::clear() noexcept
{
    Node* curr = head;
    while(curr != nullptr) 
    {
        Node* temp = curr->next;
        delete curr;
        curr = temp;
    }
    head = nullptr;
}

Node* forward_list::insert_after(Node* pos, const int val)
{
    if (!pos) throw std::out_of_range("pos is empty");
    Node* newNode = new Node{val, pos->next};

    pos->next = newNode;
    return newNode;
}

Node* forward_list::insert_after(Node* pos, size_type count, const int val)
{
    if (!pos) throw std::out_of_range("pos is empty");
    Node* last = pos;
    for (size_type i = 0; i < count; ++i) {
        Node* newNode = new Node{val, last->next};
        last->next = newNode;
        last = newNode;
    }
    return pos->next;
}

Node* forward_list::insert_after(Node* pos, std::initializer_list<int> ilist)
{
    if (!pos) throw std::out_of_range("pos is empty");
    Node* last = pos;
    for (int x : ilist) {
        Node* newNode = new Node{x, last->next};
        last->next = newNode;
        last = newNode;
    }

    return pos->next;
}

Node* forward_list::erase_after(Node* pos)
{
    if (!pos || !pos->next) throw std::out_of_range("nothing to erase");
    Node* temp = pos->next;
    pos->next = temp->next;
    delete temp;

    return pos->next;
}

Node* forward_list::erase_after(Node* first, const Node* last)
{
    if (!first) throw std::out_of_range("first is empty");
    Node* temp = first->next;
    while (temp != last) {
        if (!temp) throw std::out_of_range("invalid range");
        first->next = temp->next;
        delete temp;
        temp = first->next;
    }
    return first->next;
}

void forward_list::push_front(const int val)
{
    Node* newNode = new Node{val, head};
    head = newNode;
}

void forward_list::pop_front()
{
    if (!head) throw std::out_of_range("head is empty");
    Node* temp = head;
    head = head->next;
    delete temp;
}

void forward_list::resize(size_type count, const int val)
{
    Node* curr = head;
    Node* prev = nullptr;
    size_type i = 0;
    while (curr && i < count) {
        prev = curr;
        curr = curr->next;
        ++i;
    }

    if (i == count) {
        if (prev)
            erase_after(prev, nullptr);
        else
            clear();
    } else {
        if (!prev) {
            head = new Node{val, nullptr};
            prev = head;
            ++i;
        }
        insert_after(prev, count - i, val);
    }
}

void forward_list::swap(forward_list& other) noexcept
{
    Node* temp = other.head;
    other.head = head;
    head = temp;
}
