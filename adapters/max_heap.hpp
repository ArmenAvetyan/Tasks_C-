#pragma once
#include <vector>
#include <utility>
#include <print>

template <typename T>
class maxHeap {
    public:
        void push(const T& value) {
            heap.push_back(value);
            heapifyUp(heap.size() - 1);
        }

        void pop() {
            if(heap.empty())
                throw std::runtime_error("Heap is empty!");
            
            heap[0] = heap.back();
            heap.pop_back();

            if(!heap.empty())
                heapifyDown(0);
        }

        T top() {
            if(heap.empty())
                throw std::runtime_error("Heap is empty!");
            return heap[0];
        }

        bool empty() {
            return heap.empty();
        }

        std::size_t size() {
            return heap.size();
        }

        void build() {
            int n = heap.size();

            for (int i = n / 2 - 1; i >= 0; --i) {
                heapifyDown(i);
            }
        }

        void printh() {
            for(const T& x : heap)
                std::print("{} ", x);
            std::println();
        }

        void hsort() {
            int n = heap.size();
            build();
            
            for(int i = n - 1; i > 0; --i) {
                std::swap(heap[0], heap[i]);
                heapifyDown(0, i);
            }
        }

    private:
        std::vector<T> heap;

        void heapifyUp(int index) {
            while (index > 0) {
                int parent = (index - 1) / 2;

                if(heap[parent] >= heap[index])
                    break;

                std::swap(heap[parent], heap[index]);
                index = parent;
            }
        }

        void heapifyDown(int index) {
            int n = heap.size();

            while(true) {
                int left = index * 2 + 1;
                int right = index * 2 + 2;
                int largest = index;

                if(left < n && heap[largest] < heap[left])
                    largest = left;
                if(right < n && heap[largest] < heap[right])
                    largest = right;
                if(largest == index)
                    break;

                std::swap(heap[index], heap[largest]);
                index = largest;
            }
        }

        void heapifyDown(int index, int n) {
            while(true) {
                int left = index * 2 + 1;
                int right = index * 2 + 2;
                int largest = index;

                if(left < n && heap[largest] < heap[left])
                    largest = left;

                if(right < n && heap[largest] < heap[right])
                    largest = right;

                if(largest == index)
                    break;

                std::swap(heap[index], heap[largest]);
                index = largest;
            }
        }
};
