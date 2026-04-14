#pragma once
#include <cstddef>
#include "shared_ptr.hpp"

class WeakIntPtr {
public:
    friend class SharedIntPtr;
    WeakIntPtr();
    WeakIntPtr(const SharedIntPtr& shared);
    WeakIntPtr(const WeakIntPtr& other);
    WeakIntPtr(WeakIntPtr&& other) noexcept;
    ~WeakIntPtr();
public:
    WeakIntPtr& operator=(const WeakIntPtr& other);
    WeakIntPtr& operator=(WeakIntPtr&& other) noexcept;
public:
    bool expired() const noexcept;
    size_t use_count() const;
public:
    SharedIntPtr lock() const;
private:
    struct SharedIntPtr::ControlBlock* cb {};
    int* ptr {};
    void release();
};
