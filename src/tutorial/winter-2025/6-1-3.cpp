#include <bits/stdc++.h>

bool xis_max(int x, int y, int z) {
    return x >= y && x >= z;
}

auto find_crossing_subarray(const std::vector<int>& vec, int left, int mid, int right) -> std::tuple<int, int, int> {
    int sum = 0;
    int left_idx = left, right_idx = right;
    int left_sum = INT_MIN, right_sum = INT_MIN;
    for (int i = mid; i >= left; --i) {
        sum += vec[i];
        if (sum >= left_sum) {
            left_sum = sum;
            left_idx = i;
        }
    }
    sum = 0;
    for (int j = mid + 1; j <= right; ++j) {
        sum += vec[j];
        if (sum >= right_sum) {
            right_sum = sum;
            right_idx = j;
        }
    }
    return {left_idx, right_idx, left_sum + right_sum};
}

auto find_maximum_subarray(const std::vector<int>& vec, int left, int right) -> std::tuple<int, int, int> {
    if (left == right) {
        return {left, right, vec[left]};
    }
    int mid = left + ((right - left) >> 1);
    auto [left_low, left_high, left_sum] = find_maximum_subarray(vec, left, mid);
    auto [right_low, right_high, right_sum] = find_maximum_subarray(vec, mid + 1, right);
    auto [cross_low, cross_high, cross_sum] = find_crossing_subarray(vec, left, mid, right);
    if (xis_max(left_sum, right_sum, cross_sum)) {
        return {left_low, left_high, left_sum};
    } else if (xis_max(right_sum, left_sum, cross_sum)) {
        return {right_low, right_high, right_sum};
    } else {
        return {cross_low, cross_high, cross_sum};
    }
}

/**
 * @brief first=左边界 second=右边界 third=最大和
 */
auto find_maximum_subarray(const std::vector<int>& vec) -> std::tuple<int, int, int> {
    return find_maximum_subarray(vec, 0, vec.size() - 1);
}

int main() {
    std::vector<int> arr = {1, -2, 4, 5, -2, 8, 3, -2, 6, 3, 7, -1};
    auto [max_low, max_high, max_sum] = find_maximum_subarray(arr);
    for (int i = max_low; i < max_high; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << max_sum << std::endl;
}