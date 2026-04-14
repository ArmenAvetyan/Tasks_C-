#pragma once
#include <cstddef>

class WeakIntPtr;

class SharedIntPtr {
public:
    struct ControlBlock{
        size_t strong_count {};
        size_t weak_count {};
        int* data {};

        ControlBlock(int* p) : data{p}, strong_count{1} {}
        ~ControlBlock() = default;
};

public:
    friend class WeakIntPtr;
    explicit SharedIntPtr(int* p = nullptr);
    SharedIntPtr(const WeakIntPtr& other);
    SharedIntPtr(const SharedIntPtr& other);
    SharedIntPtr(SharedIntPtr&& other) noexcept;
    SharedIntPtr(const SharedIntPtr& other, int* alias_ptr);
    ~SharedIntPtr();
public:
    SharedIntPtr& operator=(const SharedIntPtr& other);
    SharedIntPtr& operator=(SharedIntPtr&& other) noexcept;
    int& operator*() const;
    int* operator->() const;
    explicit operator bool() const;
public:
    int* get() const;
    size_t use_count() const;
    void reset(int* p = nullptr);
    void swap(SharedIntPtr& other) noexcept;
private:
    ControlBlock* cb {};
    int* ptr;

    void release();
};

SharedIntPtr make_shared(int val);
