/**
 * @brief 数组工具类
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
     * @brief 直接插入排序，O(n^2)，稳定
     * @param arrBegin 数组起始地址
     * @param arrEnd 结尾后继的地址
     * @param comparator 比较器
     */
    template<typename T>
    static void insertionSort(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator = std::less<T>{});

    /**
     * @brief 希尔排序，O(n^2)，不稳定
     * @param arrBegin 数组起始地址
     * @param arrEnd 结尾后继的地址
     * @param comparator 比较器
     */
    template<typename T>
    static void shellSort(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator = std::less<T>{});

    /**
     * @brief 直接选择排序，O(n^2)，稳定 buggy
     * @param arrBegin 数组起始地址
     * @param arrEnd 结尾后继的地址
     * @param comparator 比较器
     */
    template<typename T>
    static void selectionSort(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator = std::less<T>{});

    /**
     * @brief 堆排序，O(n log n)，不稳定
     * @param arrBegin 数组起始地址
     * @param arrEnd 结尾后继的地址
     * @param comparator 比较器
     */
    template<typename T>
    static void heapSort(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator = std::less<T>{});

private:
    // Deprecated
    static bool checkRange(std::size_t n, std::size_t l, std::size_t r);

    template<typename T>
    static bool checkRange(T* arrBegin, T* arrEnd);

    template<typename T>
    static void swap(T& x, T& y);

    template<typename T>
    static void buildHeap(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator = std::less<T>{});

    template<typename T>
    static void shiftDown(T* arrBegin, T* arrEnd, T* heapEnd, T* k, const std::function<bool(const T&, const T&)>& comparator = std::less<T>{});

    template<typename T>
    inline static T* leftChild(T* arrBegin, T* parent);

    template<typename T>
    inline static T* rightChild(T* arrBegin, T* parent);

    template<typename T>
    inline static T* parent(T* arrBegin, T* child);
};

template<typename T>
T* ArrayUtils::linearSearch(T* arrBegin, T* arrEnd, const T& target) {
    if(!checkRange(arrBegin, arrEnd)) {
        throw IndexOutOfBoundsException();
    }

    for(T* p = arrBegin; p < arrEnd; ++p) {
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

    for(T* p = arrBegin + 1; p < arrEnd; ++p) {
        T* q = p - 1;
        while(q >= arrBegin && comparator(*p, *q)) {
            *(q + 1) = *q;
            --q;
        }
        *(q + 1) = *p;
    }
}

template<typename T>
void ArrayUtils::shellSort(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator) {
    std::size_t size = getSize(arrBegin, arrEnd);
    for(std::size_t gap = size >> 1; gap > 0; gap >>= 1) {
        for(T* p = arrBegin + gap; p < arrEnd; ++p) {
            T* q{};
            for(q = p - gap; q >= arrBegin && comparator(*p, *q); q -= gap) {
                *(q + gap) = *q;
            }
            *(q + gap) = *p;
        }
    }
}

template<typename T>
void ArrayUtils::selectionSort(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator) {
    if(!checkRange(arrBegin, arrEnd)) {
        throw IndexOutOfBoundsException();
    }

    for(T* p = arrBegin; p < arrEnd; ++p) {
        T* t = p;
        for(T* q = p + 1; q < arrEnd; ++q) {
            if(comparator(*q, *t)) {
                t = q;
            }
        }
        if(t != p) {
            swap(*p, *t);
        }
    }
}

template<typename T>
void ArrayUtils::heapSort(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator) {
    buildHeap(arrBegin, arrEnd, comparator);
    for(T* p = arrEnd - 1; p > arrBegin; --p) {
        swap(*arrBegin, *p);
        shiftDown(arrBegin, arrEnd, p, arrBegin, comparator);
    }
}

template<typename T>
bool ArrayUtils::checkRange(T* arrBegin, T* arrEnd) {
    return arrBegin && arrEnd && arrBegin <= arrEnd;
}

template<typename T>
void ArrayUtils::swap(T& x, T& y) {
    T tmp = x;
    x = y;
    y = tmp;
}

template<typename T>
void ArrayUtils::buildHeap(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator) {
    for(T* k = parent(arrEnd); k >= arrBegin; --k) {
        shiftDown(arrBegin, arrEnd, arrEnd, k, comparator);
    }
}

template<typename T>
void ArrayUtils::shiftDown(T* arrBegin, T* arrEnd, T* heapEnd, T* k, const std::function<bool(const T&, const T&)>& comparator) {
    T* tmp = (heapEnd - arrBegin) >> 1L;
    while(k < tmp) {
        T* largest = leftChild(k);
        T* right = rightChild(k);
        if(right < heapEnd && comparator(*largest, *right)) {
            largest = right;
        }
        if(comparator(*largest, *k)) {
            break;
        }
        swap(*k, *largest);
        k = largest;
    }
}

template<typename T>
T* ArrayUtils::leftChild(T* arrBegin, T* parent) {
    return ((parent - arrBegin) << 1L) + 1L;
}

template<typename T>
T* ArrayUtils::rightChild(T* arrBegin, T* parent) {
    return ((parent - arrBegin) << 1L) + 2L;
}

template<typename T>
T* ArrayUtils::parent(T* arrBegin, T* child) {
    return ((child - arrBegin) >> 1L) - 1L;
}

#endif // ARRAY_UTILS_H