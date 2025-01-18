#include <bits/stdc++.h>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = 0;
        while(l < r) {
            int v = (r - l) * std::min(height[l], height[r]);
            ans = std::max(ans, v);
            if(height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int ans = s.maxArea(height);
    std::cout << ans << std::endl;
}