/**
 * @see https://leetcode.cn/problems/squares-of-a-sorted-array/
 */
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int l = 0, r = nums.size() - 1, cur = r;
        std::vector<int> ans(nums.size());
        while (l <= r) {
            int ll = nums[l] * nums[l];
            int rr = nums[r] * nums[r];
            if (ll <= rr) {
                ans[cur--] = rr;
                --r;
            } else {
                ans[cur--] = ll;
                ++l;
            }
        }
        return ans;
    }
};

int main() {
    // Given
    Solution s{};
    std::vector<int> nums = {-4, -1, 0, 3, 10};

    // When
    auto ans = s.sortedSquares(nums);

    // Then
    for(const auto& num : nums) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}