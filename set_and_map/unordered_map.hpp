#pragma once
#include <vector>
#include <forward_list>
#include <utility>
#include <functional>
#include <memory>
#include <cstddef>
#include <stdexcept>
#include <cmath>

template <typename Key,
         typename T,
         typename Hash = std::hash<Key>,
         typename KeyEqual = std::equal_to<Key>,
         typename Allocator = std::allocator<std::pair<const Key, T>>
>
class Unordered_map {
    public:
        class iterator;
        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const Key, T>;
        using size_type = std::size_t;
        using hasher = Hash;
        using key_equal = KeyEqual;
        using allocator_type = Allocator;

    private:
        friend class iterator;
        using bucket_type = std::forward_list<value_type>;

        std::vector<bucket_type> buckets_ {};
        size_type bucket_count_ {};
        size_type size_ {};
        float max_load_factor_ {0.75f};
        
        hasher hash_;
        key_equal equal_;

        size_type bucket_index(const key_type& key) const {
            return hash_(key) % bucket_count_;
        }

    public:
        explicit Unordered_map(size_type bucket_count = 16)
            : buckets_(bucket_count == 0 ? 1 : bucket_count),
            bucket_count_(bucket_count == 0 ? 1 : bucket_count) {}

        size_type size() const noexcept{
            return size_;
        }

        bool empty() const noexcept {
            return size_ == 0;
        }

        size_type bucket_count() const noexcept {
            return bucket_count_;
        }

        float load_factor() const noexcept {
            return static_cast<float>(size_) / bucket_count_;
        }

        float max_load_factor() const noexcept {
            return max_load_factor_;
        }

        void max_load_factor(float value) {
            if(value < 0.0f)
                throw std::invalid_argument("max_load_factor must be positive");

            max_load_factor_ = value;

            if(load_factor() > max_load_factor_) {
                size_type required {
                static_cast<size_type>(
                        std::ceil(static_cast<float>(size_) / max_load_factor_))
                };
                rehash(required);
            }
        }

        bool insert(const value_type& value) {
            size_type index {bucket_index(value.first)};
            for(const auto& element : buckets_[index]) {
                if(equal_(element.first, value.first))
                    return false;
            }

            if(static_cast<float>(size_ + 1) / static_cast<float>(bucket_count_) > max_load_factor_) {
                rehash(bucket_count_ * 2);
                index = bucket_index(value.first);
            }

            buckets_[index].push_front(value);
            ++size_;
            return true;
        }

        bool insert(value_type&& value) {
            size_type index {bucket_index(value.first)};
            for(const auto& element : buckets_[index]) {
                if(equal_(element.first, value.first))
                    return false;
            }

            if(static_cast<float>(size_ + 1) / static_cast<float>(bucket_count_) > max_load_factor_) {
                rehash(bucket_count_ * 2);
                index = bucket_index(value.first);
            }

            buckets_[index].push_front(std::move(value));
            ++size_;
            return true;
        }

        iterator find(const key_type& key) {
            size_type index {bucket_index(key)};

            for(auto it {buckets_[index].begin()};
                it != buckets_[index].end(); ++it) {
                if(equal_(key, it->first))
                    return iterator(this, index, it);
            }

            return end();
        }

        bool contains(const key_type& key) const {
            size_type index {bucket_index(key)};

            for(const auto& element : buckets_[index]) {
                if(equal_(element.first, key))
                    return true;
            }
            return false;
        }

        mapped_type& at(const key_type& key) {
            iterator it {find(key)};

            if(it == end())
                throw std::out_of_range("Key not found");

            return it->second;
        }

        mapped_type& operator[](const key_type& key) {
            iterator it {find(key)};

            if(it != end())
                return it->second;

            insert(value_type{key, mapped_type{}});

            return find(key)->second;
        }

        size_type erase(const key_type& key) {
            size_type index {bucket_index(key)};

            auto& bucket {buckets_[index]};

            auto previus {bucket.before_begin()};
            auto current {bucket.begin()};

            while (current != bucket.end()) {
                if(equal_(current->first, key)) {
                    bucket.erase_after(previus);

                    --size_;
                    return 1;
                }
                previus = current;
                ++current;
            }
            return 0;
        }

        void clear() noexcept {
            for(auto& bucket : buckets_)
                bucket.clear();

            size_ = 0;
        }

        void rehash(size_type count) {
            if(count < 1)
                count = 1;
            if(static_cast<float>(size_) / count > max_load_factor_)
                return;

            std::vector<bucket_type> new_buckets_(count);

            for(auto& bucket : buckets_) {
                for(auto& element : bucket) {
                    size_type new_index {hash_(element.first) % count};

                    new_buckets_[new_index].push_front(std::move(element));
                }
            }
            buckets_ = std::move(new_buckets_);
            bucket_count_ = count;
        }

        void reserve(size_type count) {
            size_type req_bucket_count {
                static_cast<size_type>(count / max_load_factor_) + 1 };
            if(req_bucket_count > bucket_count_)
                rehash(req_bucket_count);
        }

        class iterator{
            friend class Unordered_map;

            private:
                Unordered_map* map_ {};
                size_type bucket_index_ {};
                typename bucket_type::iterator current_;

                iterator(Unordered_map* map,
                        size_type bucket_index,
                        typename bucket_type::iterator current)
                    : map_(map),
                    bucket_index_(bucket_index),
                    current_(current) {}

                void skip_empty_buckets() {
                    while (bucket_index_ < map_->bucket_count_) {
                        if(current_ != map_->buckets_[bucket_index_].end())
                            return;

                        ++bucket_index_;

                        if(bucket_index_ < map_->bucket_count_)
                            current_ = map_->buckets_[bucket_index_].begin();
                    }
                }

            public:
                using iterator_category = std::forward_iterator_tag;
                using value_type = Unordered_map::value_type;
                using difference_type = std::ptrdiff_t;
                using pointer = value_type*;
                using reference = value_type&;

                iterator() = default;

                reference operator*() const {
                    return *current_;
                }

                pointer operator->() const {
                    return &(*current_);
                }

                iterator& operator++() {
                    ++current_;
                    skip_empty_buckets();
                    return *this;
                }

                iterator operator++(int) {
                    iterator temp {*this};
                    ++(*this);
                    return temp;
                }

                bool operator==(const iterator& other) const {
                    if(map_ != other.map_)
                        return false;
                    if(map_ == nullptr)
                        return true;
                    if(bucket_index_ != other.bucket_index_)
                        return false;
                    if(bucket_index_ == map_->bucket_count_)
                        return true;
                    return current_ == other.current_;
                }

                bool operator!=(const iterator& other) const {
                    return !(*this == other);
                }
        };

        iterator begin() {
            iterator it (this, 0, buckets_[0].begin());
            it.skip_empty_buckets();
            return it;
        }

        iterator end() {
            return iterator(this, bucket_count_, {});
        }
};
