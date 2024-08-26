/**
 * @see https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 */
#include <bits/stdc++.h>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }

private:
    int quickSelect(std::vector<int>& nums, int l, int r, int k) {
        if (l == r) {
            return nums[k];
        }
        int partition = nums[l], i = l - 1, j = r + 1;
        while (i < j) {
            do ++i; while (nums[i] < partition);
            do --j; while(nums[j] > partition);
            if(i < j) {
                std::swap(nums[i], nums[j]);
            }
        }

        if(k <= j) {
            return quickSelect(nums, l, j, k);
        } else {
            return quickSelect(nums, j + 1, r, k);
        }
    }
};

int main() {
    // Given
    Solution s;
    std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    // When
    int res = s.findKthLargest(nums, k);

    // Then
    std::cout << res << std::endl;
}