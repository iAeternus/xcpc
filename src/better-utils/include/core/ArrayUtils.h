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

    template<typename T>
    static std::size_t getSize(const T* arrBegin, const T* arrEnd);

private:
    static bool checkRange(std::size_t n, std::size_t l, std::size_t r);

    template<typename T>
    static bool checkRange(T* arrBegin, T* arrEnd);
};

template<typename T>
T* ArrayUtils::linearSearch(T* arrBegin, T* arrEnd, const T& target) {
    if(!checkRange(arrBegin, arrEnd)) {
        throw IndexOutOfBoundsException();
    }

    T* p = arrBegin;
    while(p != arrEnd) {
        if(*p++ == target) {
            return p - 1;
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
std::size_t ArrayUtils::getSize(const T* arrBegin, const T* arrEnd) {
    if(!checkRange(arrBegin, arrEnd)) {
        throw IndexOutOfBoundsException();
    }

    return arrEnd - arrBegin;
}

template<typename T>
bool ArrayUtils::checkRange(T* arrBegin, T* arrEnd) {
    return arrBegin && arrEnd && arrBegin <= arrEnd;
}

#endif // ARRAY_UTILS_H