#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }
    int l, r;
    std::cin >> l >> r;

    if (sum > n * r || sum < n * l) {
        std::cout << -1 << std::endl;
        return 0;
    }

    i64 max_add = 0, max_diff = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < l) {
            max_add += l - a[i];
        }
        if (r < a[i]) {
            max_diff += a[i] - r;
        }
    }
    std::cout << std::max(max_add, max_diff) << std::endl;
}