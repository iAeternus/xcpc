#include <bits/stdc++.h>

template <typename T, typename C>
void merge(std::vector<T>& vec, int left, int mid, int right, C compare) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<T> leftVec(n1), rightVec(n2);
    int i, j;
    for (int i = 0; i < n1; ++i) {
        leftVec[i] = vec[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightVec[j] = vec[mid + j + 1];
    }
    i = j = 0;
    int pos = left;
    while (i < n1 && j < n2) {
        if (compare(leftVec[i], rightVec[j])) {
            vec[pos++] = leftVec[i++];
        } else {
            vec[pos++] = rightVec[j++];
        }
    }
    while (i < n1) {
        vec[pos++] = leftVec[i++];
    }
    while (j < n2) {
        vec[pos++] = rightVec[j++];
    }
}

template <typename T, typename C>
void sort(std::vector<T>& vec, int left, int right, C compare) {
    if (left >= right) return;
    int mid = left + ((right - left) >> 1);
    sort(vec, left, mid, compare);
    sort(vec, mid + 1, right, compare);
    merge(vec, left, mid, right, compare);
}

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