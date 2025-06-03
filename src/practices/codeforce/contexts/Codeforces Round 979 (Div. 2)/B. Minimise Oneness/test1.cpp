/**
 * @see https://codeforces.com/contest/2030/problem/B
 */
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        if (n == 1) {
            std::cout << "0" << std::endl;
        } else if (n == 2) {
            std::cout << "01" << std::endl;
        } else {
            std::cout << "01";
            for (int i = 0; i < n - 2; ++i) {
                std::cout << "0";
            }
            std::cout << std::endl;
        }
    }
}