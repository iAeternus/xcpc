/**
 * https://www.luogu.com.cn/problem/B4021
 */
#include <bits/stdc++.h>

int main() {
    int n, t;
    std::cin >> n >> t;

    std::vector<int> nums;
    for(int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        nums.push_back(a % ((int) pow(10, t)));
    }

    std::set<int> s(nums.begin(), nums.end());

    std::cout << s.size();
}