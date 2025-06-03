#include <bits/stdc++.h>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int ans = INT_MAX, sum = 0;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            sum += nums[j]; // 入滑动窗口
            while (sum >= target) {
                ans = std::min(ans, j - i + 1);
                sum -= nums[i++]; // 出滑动窗口
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
}