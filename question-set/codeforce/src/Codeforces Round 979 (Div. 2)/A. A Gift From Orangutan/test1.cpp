/**
 * @see https://codeforces.com/contest/2030/problem/0
 */
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;

        int num, max_num = -1, min_num = INT_MAX;
        for(int i = 1; i <= n; ++i) {
            std::cin >> num;
            max_num = std::max(max_num, num);
            min_num = std::min(min_num, num);
        }

        std::cout << (max_num - min_num) * (n - 1) << std::endl;
    }
}