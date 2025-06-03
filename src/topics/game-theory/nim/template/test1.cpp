/**
 * @see https://www.luogu.com.cn/problem/P2197
 */
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        int xorSum = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            xorSum ^= num;
        }

        std::cout << (xorSum == 0 ? "No" : "Yes") << std::endl;
    }
}