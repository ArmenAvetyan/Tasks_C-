#include "shared_ptr.hpp"
#include "weak_ptr.hpp"
#include <utility>

SharedIntPtr::SharedIntPtr(int* p) : ptr{p}, cb{p ? new ControlBlock(p) : nullptr} {}

SharedIntPtr::SharedIntPtr(const WeakIntPtr& other) : ptr{other.ptr}, cb{other.cb}
{
    if(cb && cb->strong_count > 0) {
        cb->strong_count++;
    } else {
        ptr = nullptr;
        cb = nullptr;
    }
}

SharedIntPtr::SharedIntPtr(const SharedIntPtr& other) : cb{other.cb}, ptr{other.ptr}
{
    if (cb)
        (cb->strong_count)++;
}

SharedIntPtr::SharedIntPtr(SharedIntPtr&& other) noexcept : cb{other.cb}, ptr{other.ptr}
{
    other.cb = nullptr;
    other.ptr = nullptr;
}

SharedIntPtr::SharedIntPtr(const SharedIntPtr& other, int* alias_ptr) : cb{other.cb}, ptr{alias_ptr}
{
    if(cb)
        (cb->strong_count)++;
}

SharedIntPtr::~SharedIntPtr()
{
    release();
}

SharedIntPtr& SharedIntPtr::operator=(const SharedIntPtr& other)
{   
    if(this != &other)
    {
        release();
        cb = other.cb;
        ptr = other.ptr;
        if(cb)
            (cb->strong_count)++;
    }
    return *this;
}

SharedIntPtr& SharedIntPtr::operator=(SharedIntPtr&& other) noexcept
{
    if(this != &other)
    {
        release();
        cb = other.cb;
        ptr = other.ptr;
        other.cb = nullptr;
        other.ptr = nullptr;
    }
    return *this;
}

int& SharedIntPtr::operator*() const
{
    return *ptr;
}

int* SharedIntPtr::operator->() const
{
    return ptr;
}

SharedIntPtr::operator bool() const
{
    return cb != nullptr;
}

int* SharedIntPtr::get() const
{
    return ptr;
}

size_t SharedIntPtr::use_count() const
{
    return cb ? cb->strong_count : 0;
}

void SharedIntPtr::reset(int* p)
{
    release();
    if(p) 
    {
        cb = new ControlBlock(p);
        ptr = p;
    } else 
    {
        cb = nullptr;
        ptr = nullptr;
    }
}

void SharedIntPtr::swap(SharedIntPtr& other) noexcept
{
    std::swap(cb, other.cb);
    std::swap(ptr, other.ptr);
}

void SharedIntPtr::release()
{
    if(cb) {
        cb->strong_count--;
        if(cb->strong_count == 0)
            delete cb->data;
        if(cb->strong_count == 0 && cb->weak_count == 0)
            delete cb;
        cb = nullptr;
        ptr = nullptr;
    }
}

SharedIntPtr make_shared(int val)
{
    return SharedIntPtr(new int(val));
}
