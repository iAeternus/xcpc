/**
 * @see https://pintia.cn/problem-sets/1892625959812247552/exam/problems/type/7?problemSetProblemId=1892626247629582343&page=0
 */
#include <bits/stdc++.h>

int find(const std::vector<int>& v, int target) {
    for(int i = 0; i < v.size(); ++i) {
        if(v[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::string s;
    std::cin >> s;
    bool hash[10] = {false};
    for(int i = 0; i < s.size(); ++i) {
        hash[s[i] - '0'] = true;
    }
    std::vector<int> nums;
    for(int i = 9; i >= 0; --i) {
        if(hash[i]) {
            nums.push_back(i);
        }
    }
    std::vector<int> v;
    for(int i = 0; i < s.size(); ++i) {
        v.push_back(find(nums, s[i] - '0'));
    }
    std::cout << "int[] arr = new int[]{";
    for(int i = 0; i < nums.size(); ++i) {
        if(i) {
            std::cout << ',';
        }
        std::cout << nums[i];
    }
    std::cout << "};\n";
    std::cout << "int[] index = new int[]{";
    for(int i = 0; i < v.size(); ++i) {
        if(i) {
            std::cout << ',';
        }
        std::cout << v[i];
    }
    std::cout << "};\n";
}