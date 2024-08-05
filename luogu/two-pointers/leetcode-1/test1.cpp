/**
 * https://leetcode.cn/problems/two-sum/
 * 
 * 稍稍改动了一下题目，现在返回两个数而不是下标
 */
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        std::vector<int> ans;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum > target) {
                --right;
            }
            if (sum < target) {
                ++left;
            }

            if (sum == target) {
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                break;
            }
        }

        return ans;
    }
};

int main() {
    // Given
    Solution s;

    std::vector<int> nums{3, 2, 4};
    int target = 6;

    // When
    std::vector<int> ans = s.twoSum(nums, target);

    // Then
    for(auto it : ans) {
        std::cout << it << ' ';
    }
}