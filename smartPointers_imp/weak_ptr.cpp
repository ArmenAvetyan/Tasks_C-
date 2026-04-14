#include "weak_ptr.hpp"
#include "shared_ptr.hpp"

WeakIntPtr::WeakIntPtr() {}

WeakIntPtr::WeakIntPtr(const SharedIntPtr& shared) : cb{shared.cb}, ptr{shared.ptr}
{
    if(cb)
        cb->weak_count++;
}

WeakIntPtr::WeakIntPtr(const WeakIntPtr& other) : cb{other.cb}, ptr{other.ptr}
{
    if(cb)
        cb->weak_count++;
}

WeakIntPtr::WeakIntPtr(WeakIntPtr&& other) noexcept : cb{other.cb}, ptr{other.ptr} 
{
    other.cb = nullptr;
    other.ptr = nullptr;
}

WeakIntPtr::~WeakIntPtr()
{
    release();
}

WeakIntPtr& WeakIntPtr::operator=(const WeakIntPtr& other)
{
    if(this != &other) {
        release();
        cb = other.cb;
        ptr = other.ptr;
        if(cb)
            cb->weak_count++;
    }
    return *this;
}

WeakIntPtr& WeakIntPtr::operator=(WeakIntPtr&& other) noexcept
{
    if(this != &other) {
        release();
        cb = other.cb;
        ptr = other.ptr;
        other.cb = nullptr;
        other.ptr = nullptr;
    }
    return *this;
}

bool WeakIntPtr::expired() const noexcept
{
    return !cb || cb->strong_count == 0;
}

size_t WeakIntPtr::use_count() const
{
    return cb ? cb->strong_count : 0;
}

SharedIntPtr WeakIntPtr::lock() const
{
    return SharedIntPtr(*this);
}

void WeakIntPtr::release()
{
    if(cb) {
        cb->weak_count--;
        if(cb->strong_count == 0 && cb->weak_count == 0)
            delete cb;
        cb = nullptr;
        ptr = nullptr;
    }
}
