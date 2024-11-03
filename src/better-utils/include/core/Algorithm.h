/**
 * @brief 常用算法
 * @author Ricky
 * @date 2024/11/3
 * @version 1.0
 */
#ifndef ALGORITHM_H
#define ALGORITHM_H

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
     * @return 找到返回索引，否则返回 -1
     */
    template<typename T>
    static std::size_t linearSearch(T* arr, std::size_t n, const T& target, std::size_t l, std::size_t r);

    template<typename T>
    static std::size_t linearSearch(T* arr, std::size_t n, const T& target);

private:
    static bool checkRange(std::size_t n, std::size_t l, std::size_t r);
};

#endif // ALGORITHM_H