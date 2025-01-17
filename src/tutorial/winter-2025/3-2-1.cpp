#include <bits/stdc++.h>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int ans = INT_MAX, sum = 0;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            sum += nums[j]; // 入
            while (sum >= target) {
                ans = std::min(ans, j - i + 1); // 更新结果
                sum -= nums[i++];               // 出
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    // Given
    Solution s{};
    int target = 7;
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};

    // When
    int ans = s.minSubArrayLen(target, nums);

    // Then
    assert(ans == 2);
}