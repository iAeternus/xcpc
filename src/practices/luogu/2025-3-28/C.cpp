#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        i64 n;
        std::cin >> n;
        if (n % 3 == 0) {
            std::cout << n * 2 << std::endl;
        } else {
            std::cout << n << std::endl;
        }
    }
}