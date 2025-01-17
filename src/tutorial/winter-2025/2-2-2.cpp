#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int n, m;
    std::cin >> n >> m;
    i64 sum = 0, sum2 = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            sum += std::min(i, j); // 正方形个数
            sum2 += i * j; // 矩形个数
        }
    }
    std::cout << sum << ' ' << sum2 - sum << std::endl;
}