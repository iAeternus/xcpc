#include <bits/stdc++.h>

template<typename T, typename C>
int partition(std::vector<T>& vec, int left, int right, C compare) {
    T pivot = vec[right];
    int i = left;
    for(int j = left; j < right; ++j) {
        if(compare(vec[j], pivot)) { // <
            std::swap(vec[i++], vec[j]);
        }
    }
    std::swap(vec[i], vec[right]);
    return i; // 主元的索引
}

template<typename T, typename C>
void sort(std::vector<T>& vec, int left, int right, C compare) {
    if(left >= right) return;
    int pivotIdx = partition(vec, left, right, compare);
    sort(vec, left, pivotIdx - 1, compare); // 左
    sort(vec, pivotIdx + 1, right, compare); // 右
}

/**
 * @brief 最终的接口
 */
template<typename T, typename C>
void sort(std::vector<T>& vec, C compare) {
    sort(vec, 0, vec.size() - 1, compare);
}

int main() {
    std::vector<int> nums = {6, 5, 7, 4, 8, 3, 9, 2, 0, 1};
    sort(nums, std::less<int>{});
    for(const auto& num : nums) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    sort(nums, [](int a, int b) {
        return a > b;
    });
    for(const auto& num : nums) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}