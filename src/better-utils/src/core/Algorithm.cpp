#include "Algorithm.h"
#include "IndexOutOfBoundsException.h"

template <typename T>
std::size_t Algorithm::linearSearch(T* arr, std::size_t n, const T& target, std::size_t l, std::size_t r) {
    if (!checkRange(n, l, r)) {
        throw IndexOutOfBoundsException();
    }

    for (std::size_t i = l; i < r; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

template <typename T>
std::size_t Algorithm::linearSearch(T* arr, std::size_t n, const T& target) {
    return linearSearch(arr, n, target, 0, n - 1);
}

bool Algorithm::checkRange(std::size_t n, std::size_t l, std::size_t r) {
    return l <= r && r < n;
}