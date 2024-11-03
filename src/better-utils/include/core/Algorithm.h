/**
 * @brief 常用算法
 * @author Ricky
 * @date 2024/11/3
 * @version 1.0
 */
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "IndexOutOfBoundsException.h"

#include <cstddef>

class Algorithm {
public:
    Algorithm() = delete;

    /**
     * @brief 线性查找，区间 [l, r)
     * @param arr 数组
     * @param n 数组长度
     * @param l 左闭区间
     * @param r 右开区间
     * @return 找到返回索引，否则返回 n
     */
    template<typename T>
    static std::size_t linearSearch(T* arr, std::size_t n, const T& target, std::size_t l, std::size_t r);

    template<typename T>
    static std::size_t linearSearch(T* arr, std::size_t n, const T& target);

    /**
     * @brief 二分查找，区间 [l, r)
     * @param arr 数组
     * @param n 数组长度
     * @param l 左闭区间
     * @param r 右开区间
     * @return 找到返回索引，否则返回 n
     */
    template<typename T>
    static std::size_t binarySearch(T* arr, std::size_t n, const T& target, std::size_t l, std::size_t r);

    template<typename T>
    static std::size_t binarySearch(T* arr, std::size_t n, const T& target);

private:
    static bool checkRange(std::size_t n, std::size_t l, std::size_t r);
};

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
    return n;
}

template <typename T>
std::size_t Algorithm::linearSearch(T* arr, std::size_t n, const T& target) {
    return linearSearch(arr, n, target, 0, n);
}

template<typename T>
std::size_t Algorithm::binarySearch(T* arr, std::size_t n, const T& target, std::size_t l, std::size_t r) {
    if (!checkRange(n, l, r)) {
        throw IndexOutOfBoundsException();
    }

    std::size_t left = l, right = r - 1;
    while(left <= right) {
        std::size_t mid = left + ((right - left) >> 1);
        if(arr[mid] < target) {
            left = mid + 1;
        } else if(arr[mid] > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return n;
}

template<typename T>
std::size_t Algorithm::binarySearch(T* arr, std::size_t n, const T& target) {
    return binarySearch(arr, n, target, 0, n);
}

#endif // ALGORITHM_H