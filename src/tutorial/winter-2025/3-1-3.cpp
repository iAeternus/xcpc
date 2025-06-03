#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int l = 0, r = nums.size() - 1, pos = r;
        std::vector<int> ans(nums.size());
        while (l <= r) {
            int ll = nums[l] * nums[l];
            int rr = nums[r] * nums[r];
            if (ll <= rr) {
                ans[pos--] = rr;
                --r;
            } else {
                ans[pos--] = ll;
                ++l;
            }
        }
        return ans;
    }
};

int main() {
}