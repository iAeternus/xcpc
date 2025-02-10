#include <bits/stdc++.h>

template <typename T, typename C>
int partition(std::vector<T>& vec, int left, int right, C compare) {
    T pivot = vec[right];
    int i = left; // i的左边都是比主元小的
    for (int j = left; j < right; ++j) {
        if (compare(vec[j], pivot)) { // 可以看成 <
            std::swap(vec[i++], vec[j]);
        }
    }
    std::swap(vec[i], vec[right]);
    return i;
}

template <typename T, typename C>
void sort(std::vector<T>& vec, int left, int right, C compare) {
    if (left >= right) return;
    int pivotIdx = partition(vec, left, right, compare); // 获取排好的主元索引
    sort(vec, left, pivotIdx - 1, compare);              // 递归主元左边
    sort(vec, pivotIdx + 1, right, compare);             // 递归主元右边
}

/**
 * @brief 快速排序，不稳定，时间复杂度O(n log n)
 */
template <typename T, typename C>
void sort(std::vector<T>& vec, C compare) {
    sort(vec, 0, vec.size() - 1, compare);
}

int main() {
    std::vector<int> nums = {6, 5, 7, 4, 8, 3, 9, 2, 0, 1};
    sort(nums, std::less<int>{});
    for (const auto& num : nums) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    sort(nums, std::greater<int>{});
    for (const auto& num : nums) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}