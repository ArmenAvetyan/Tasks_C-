#pragma once
#include <vector>
#include <forward_list>
#include <cstddef>

template <typename T, typename Hash = std::hash<T>>
class Unordered_set {
    public:
        class iterator;
        explicit Unordered_set(std::size_t bcount = 8)
            : buckets_(bcount == 0 ? 1 : bcount), size_(0) {}

        bool insert(const T& value) {
            std::size_t idx {bucket_idx(value)};
            for(const auto& elem : buckets_[idx]) {
                if(elem == value) return false;
            }

            if(static_cast<double>(size_ + 1) / buckets_.size() > mload_factor_) {
                rehash(buckets_.size() * 2);
                idx = bucket_idx(value);
            }

            buckets_[idx].push_front(value);
            ++size_;
            return true;
        }

        bool contains(const T& value) const {
            std::size_t idx {bucket_idx(value)};
            const auto& bucket {buckets_[idx]};

            for(const auto& elem : bucket) {
                if(elem == value) return true;
            }
            return false;
        }

        bool erase(const T& value) {
            std::size_t idx {bucket_idx(value)};
            auto& bucket {buckets_[idx]};

            auto prev {bucket.before_begin()};

            for(auto It {bucket.begin()}; It != bucket.end(); ++It, ++prev) {
                if(*It == value) {
                    bucket.erase_after(prev);
                    --size_;
                    return true;
                }
            }
            return false;
        }

        bool empty() const { return size_ == 0; }

        iterator find(const T& value) {
            std::size_t idx {bucket_idx(value)};
            auto& bucket {buckets_[idx]};

            for(auto it = bucket.begin(); it != bucket.end(); ++it) {
                if(*it == value)
                    return iterator(this, idx, it);
            }
            return end();
        }

        void clear() {
            for(auto& bucket : buckets_)
                bucket.clear();
            size_ = 0;
        }

        std::size_t size() const { return size_; }

        std::size_t bucket_count() const { return buckets_.size(); }

        double load_factor() const {
            return static_cast<double>(size_) / buckets_.size();
        }

        iterator begin() {
            for(std::size_t i {}; i < buckets_.size(); ++i) {
                if(!buckets_[i].empty())
                    return iterator(this, i, buckets_[i].begin());
            }
            return end();
        }

        iterator end() {
            return iterator(this, buckets_.size(), {});
        }

        class iterator {
            public:
                iterator() = default;

                iterator(Unordered_set* set, std::size_t b_idx, typename std::forward_list<T>::iterator it)
                    : set_(set), bucket_idx_(b_idx), it_(it) {}

                T& operator*() {
                    return *it_;
                }

                T* operator->() {
                    return &(*it_);
                }

                bool operator==(const iterator& other) const {
                    return bucket_idx_ == other.bucket_idx_ &&
                        it_ == other.it_;
                }

                bool operator!=(const iterator& other) const {
                    return !(*this == other);
                }

                iterator& operator++() {
                    ++it_;

                    if(it_ != set_->buckets_[bucket_idx_].end())
                        return *this;

                    ++bucket_idx_;

                    while(bucket_idx_ < set_->buckets_.size()) {
                        if(!set_->buckets_[bucket_idx_].empty()) {
                            it_ = set_->buckets_[bucket_idx_].begin();
                            return *this;
                        }
                        ++bucket_idx_;
                    }

                    it_ = {};
                    return *this;
                }

            private:
                Unordered_set* set_ {};
                std::size_t bucket_idx_ {};
                typename std::forward_list<T>::iterator it_ {};
        };

    private:
        friend class iterator;
        std::vector<std::forward_list<T>> buckets_;
        Hash hasher_;
        std::size_t size_ {};
        double mload_factor_ {0.75};

        std::size_t bucket_idx(const T& value) const {
            return hasher_(value) % buckets_.size();
        }

        void rehash(std::size_t new_count) {
            std::vector<std::forward_list<T>> new_b(new_count);

            for (auto& buck : buckets_) {
                for (auto& elem : buck) {
                    std::size_t idx {hasher_(elem) % new_count};
                    new_b[idx].push_front(std::move(elem));
                }
            }
            buckets_ = std::move(new_b);
        }
};
