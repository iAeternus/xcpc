#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if ((i * i) % n < double(n / 2.0)) {
            ++cnt;
        }
    }
    std::cout << cnt << std::endl;
}