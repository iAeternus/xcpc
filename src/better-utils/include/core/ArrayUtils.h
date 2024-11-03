/**
 * @brief 常用算法
 * @author Ricky
 * @date 2024/11/3
 * @version 1.0
 */
#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include "IndexOutOfBoundsException.h"

#include <cstddef>
#include <functional>

class ArrayUtils {
public:
    ArrayUtils() = delete;

    /**
     * @brief 线性查找，区间 [l, r)
     * @param arrBegin 数组起始地址
     * @param arrEnd 结尾后继的地址
     * @param target 查找目标
     * @return 找到返回指向目标的指针，否则返回 nullptr
     */
    template<typename T>
    static T* linearSearch(T* arrBegin, T* arrEnd, const T& target);

    /**
     * @brief 二分查找，区间 [l, r)
     * @param arrBegin 数组起始地址
     * @param arrEnd 结尾后继的地址
     * @param target 查找目标
     * @return 找到返回指向目标的指针，否则返回 nullptr
     */
    template<typename T>
    static T* binarySearch(T* arrBegin, T* arrEnd, const T& target);

    /**
     * @brief 计算长度，区间 [arrBegin, arrEnd]
     * @param from 起始地址
     * @param to 终止地址
     * @return 返回指针间距长度
     */
    template<typename T>
    static std::size_t getSize(const T* from, const T* to);

    /**
     * @brief 直接插入排序，O(n^2)
     * @param arrBegin 数组起始地址
     * @param arrEnd 结尾后继的地址
     */
    template<typename T>
    static void insertionSort(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator = std::less<T>{});

private:
    // Deprecated
    static bool checkRange(std::size_t n, std::size_t l, std::size_t r);

    template<typename T>
    static bool checkRange(T* arrBegin, T* arrEnd);
};

template<typename T>
T* ArrayUtils::linearSearch(T* arrBegin, T* arrEnd, const T& target) {
    if(!checkRange(arrBegin, arrEnd)) {
        throw IndexOutOfBoundsException();
    }

    for(T* p = arrBegin; p != arrEnd; ++p) {
        if(*p == target) {
            return p;
        }
    }
    return nullptr;
}

template<typename T>
T* ArrayUtils::binarySearch(T* arrBegin, T* arrEnd, const T& target) {
    if(!checkRange(arrBegin, arrEnd)) {
        throw IndexOutOfBoundsException();
    }

    T* left = arrBegin;
    T* right = arrEnd - 1;
    while(left <= right) {
        T* mid = left + ((right - left) >> 1L);
        if(*mid < target) {
            left = mid + 1;
        } else if(*mid > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return nullptr;
}

template<typename T>
std::size_t ArrayUtils::getSize(const T* from, const T* to) {
    if(!checkRange(from, to)) {
        throw IndexOutOfBoundsException();
    }

    return to - from;
}

template<typename T>
void ArrayUtils::insertionSort(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator) {
    if(!checkRange(arrBegin, arrEnd)) {
        throw IndexOutOfBoundsException();
    }

    for(T* p = arrBegin + 1; p != arrEnd; ++p) {
        T* q = p - 1;
        while(q >= arrBegin && comparator(*p, *q)) {
            *(q + 1) = *q;
            --q;
        }
        *(q + 1) = *p;
    }
}

template<typename T>
bool ArrayUtils::checkRange(T* arrBegin, T* arrEnd) {
    return arrBegin && arrEnd && arrBegin <= arrEnd;
}

#endif // ARRAY_UTILS_H