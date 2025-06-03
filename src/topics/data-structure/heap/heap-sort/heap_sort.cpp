#include <bits/stdc++.h>

#define LEFT(x) (((x) << 1) + 1)
#define RIGHT(x) (((x) << 1) + 2)
#define PARENT(x) (((x) >> 1) - 1)

template <class T>
void swap(T& x, T& y) {
    T tmp = x;
    x = y;
    y = tmp;
}

template <class T>
void shift_down(T* nums, int size, int heap_size, int k, const std::function<bool(const T&, const T&)>& func) {
    int tmp = heap_size >> 1;
    while (k < tmp) {
        int largest = LEFT(k);
        int right = RIGHT(k);
        if (right < heap_size && !func(nums[right], nums[largest])) {
            largest = right;
        }
        if (!func(nums[k], nums[largest])) {
            break;
        }
        swap(nums[k], nums[largest]);
        k = largest;
    }
}

template <class T>
void build_heap(T* nums, int size, const std::function<bool(const T&, const T&)>& func) {
    int tmp = PARENT(size);
    for (int k = tmp; k >= 0; --k) {
        shift_down(nums, size, size, k, func);
    }
}

template <class T>
void heap_sort(T* nums, int size, const std::function<bool(const T&, const T&)>& func = std::less<T>()) {
    build_heap(nums, size, func);

    for (int i = size - 1; i > 0; --i) {
        swap(nums[0], nums[i]);
        shift_down(nums, size, i, 0, func);
    }
}

void test_heap_sort() {
    // Given
    int size = 100;
    int nums[size];
    for (int i = 0; i < size; ++i) {
        nums[i] = rand() % 100;
    }

    // When
    heap_sort<int>(nums, size);

    // Then
    for (int i = 0; i < size; ++i) {
        std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;

    for (int i = 1; i < size; ++i) {
        assert(nums[i - 1] <= nums[i]);
    }

    // When
    heap_sort<int>(nums, size, [](const int& x, const int& y) {
        return x > y;
    });

    // Then
    for (int i = 0; i < size; ++i) {
        std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;

    for (int i = 1; i < size; ++i) {
        assert(nums[i - 1] >= nums[i]);
    }
}

int main() {
    srand((unsigned)time(nullptr));

    test_heap_sort();
}