// 迭代器失效
#include <bits/stdc++.h>

int main() {
    std::vector<int> nums;
    for(int i = 0; i < 10; ++i) {
        nums.push_back(i);
    }

    // for(auto it = nums.begin(); it != nums.end(); ++it) {
    //     if(*it > 3) {
    //         nums.erase(it);
    //     }
    //     std::cout << *it << ' ';
    // }
    // std::cout << std::endl;

    for(auto it = nums.begin(); it != nums.end(); ) {
        if(*it > 3) {
            it = nums.erase(it);
        } else {
            ++it;
        }
    }
    
    for(const auto& num : nums) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
}