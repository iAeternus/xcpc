#include <bits/stdc++.h>

using i64 = long long;

int main() {
    i64 n;
    std::cin >> n;
    int sqrt_n = std::sqrt(n) + 1;
    int max_len = 0, first = 0;
    for (int i = 2; i <= sqrt_n; ++i) {
        int cur = 1, len = 0;
        for (int j = i; j <= sqrt_n; ++j) {
            cur *= j;
            if (n % cur != 0) {
                break;
            }
            ++len;
        }
        if (len > max_len) {
            max_len = len;
            first = i;
        }
    }

    if (first == 0) {
        std::cout << 1 << std::endl;
        std::cout << n << std::endl;
    } else {
        std::cout << max_len << std::endl;
        for (int i = 0; i < max_len; ++i) {
            if (i) {
                std::cout << '*';
            }
            std::cout << first + i;
        }
        std::cout << std::endl;
    }
}