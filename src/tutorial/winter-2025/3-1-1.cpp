#include <bits/stdc++.h>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int s = 0;
        for(int f = 0; f < nums.size(); ++f) {
            if(nums[f] != val) {
                nums[s++] = nums[f];
            }
        }
        return s;
    }
};

int main() {
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution s;
    int n = s.removeElement(nums, val);
    for(int i = 0; i < n; ++i) {
        std::cout << nums[i] << ' ';
    }
    std::cout << std::endl;
}