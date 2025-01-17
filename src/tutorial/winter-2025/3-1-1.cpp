/**
 * @see https://leetcode.cn/problems/remove-element/description/
 */
#include <bits/stdc++.h>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

int main() {
    // Given
    Solution s{};
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    // When
    int newSize = s.removeElement(nums, val);

    // Then
    std::cout << newSize << std::endl;
    for (int i = 0; i < newSize; ++i) {
        std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;
}