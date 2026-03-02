#include "vector.hpp"
#include <utility>

//private
inline auto vector::m_alloc()
{
    size_t new_cap = m_capacity == 0 ? 1 : m_capacity * 2;
    return std::make_unique<int[]>(new_cap);
}

void vector::m_resize(size_t count, int val)
{
    if (count < m_size)
    {
        m_size = count;
        return;
    }

    if (count > m_capacity)
    {
        auto new_ptr = std::make_unique<int[]>(count * 2);

        for (size_t i = 0; i < m_size; ++i)
            new_ptr[i] = m_ptr[i];

        m_ptr = std::move(new_ptr);
        m_capacity = count * 2;
    }

    for (size_t i = m_size; i < count; ++i)
        m_ptr[i] = val;

    m_size = count;
}

//public
void vector::clear()
{
    m_size = 0;
}

size_t vector::insert(size_t pos, int val)
{
    if (pos > m_size)
        pos = m_size;

    if (m_size == m_capacity) 
    {
        auto new_ptr = m_alloc();

        for (size_t i = 0; i < pos; ++i)
            new_ptr[i] = m_ptr[i];

        new_ptr[pos] = val;

        for (size_t i = pos; i < m_size; ++i)
            new_ptr[i + 1] = m_ptr[i];

        m_capacity *= 2;
        m_ptr = std::move(new_ptr);
    } else
    {
        for (int i = m_size; i > pos; --i)
            m_ptr[i] = m_ptr[i - 1];

        m_ptr[pos] = val;
    }

    ++m_size;
    return pos;
}

size_t vector::insert(size_t pos, size_t count, int val)
{
    if (pos > m_size)
        pos = m_size;
    if (count == 0)
        return pos;

    if (m_size + count > m_capacity)
    {
        auto new_ptr = std::make_unique<int[]>((m_size + count) * 2);
        m_capacity = (m_size + count) * 2;

        for (size_t i = 0; i < pos; ++i)
            new_ptr[i] = std::move(m_ptr[i]);

        for (size_t i = 0; i < count; ++i)
            new_ptr[pos + i] = val;

        for (size_t i = pos; i < m_size; ++i)
            new_ptr[i + count] = std::move(m_ptr[i]);
        
        m_ptr = std::move(new_ptr);
    } else 
    {
        for (size_t i = m_size; i > pos; --i)
            m_ptr[i - 1 + count] = m_ptr[i - 1];

        for (size_t i = 0; i < count; ++i)
            m_ptr[pos + i] = val;
    }

    m_size += count;
    return pos;
}

size_t vector::insert(size_t pos, std::initializer_list<int> ilist)
{
    if(pos > m_size)
        pos = m_size;
    if(ilist.size() == 0)
        return pos;

    size_t count = ilist.size();

    if (m_size + count > m_capacity)
    {
        auto new_ptr = std::make_unique<int[]>((m_size + count) * 2);
        m_capacity = (m_size + count) * 2;

        for (size_t i = 0; i < pos; ++i)
            new_ptr[i] = m_ptr[i];

        size_t i = 0;
        for (int x : ilist) {
            new_ptr[pos + i] = x;
            ++i;
        }
            

        for (size_t i = pos; i < m_size; ++i)
            new_ptr[i + count] = m_ptr[i];

        m_ptr = std::move(new_ptr);
    } else 
    {
        for (size_t i = m_size; i > pos; --i)
            m_ptr[i - 1 + count] = m_ptr[i - 1];

        size_t i = 0;
        for (int x : ilist) {
            m_ptr[pos + i] = x;
            ++i;
        }
    }
    m_size += count;
    return pos;
}

size_t vector::erase(size_t pos)
{
    if (pos > m_size) 
        return m_size;

    for (size_t i = pos; i < m_size; ++i)
        m_ptr[i] = m_ptr[i + 1];

        --m_size;
        return pos;
}

size_t vector::erase(size_t first, size_t last) 
{
    if (first >= m_size || last > m_size || first >= last)
        return m_size;

    size_t count = last - first;

    for (size_t i = first; i < m_size - count; ++i)
        m_ptr[i] = m_ptr[i + count];

    m_size -= count;
    return first;
}

void vector::push_back(int val)
{
    if (m_size == m_capacity) 
    {
        auto new_ptr = m_alloc();
        
        for (size_t i = 0; i < m_size; ++i)
            new_ptr[i] = m_ptr[i];

        m_ptr = std::move(new_ptr);
        m_capacity *= 2;
    }

    m_ptr[m_size++] = val;
}

void vector::pop_back() 
{
    if (m_size == 0) return;
    --m_size;
}

void vector::resize(size_t count)
{
    int val = 0;
    m_resize(count, val);
}

void vector::resize(size_t count, int val)
{
    m_resize(count, val);
}

void vector::swap(vector& other) 
{
    std::swap(m_ptr, other.m_ptr);
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
}

void vector::print()
{
    for(int i = 0; i < m_size; ++i)
        std::cout << m_ptr[i] << ' ';
    
    std::cout << std::endl;
}
