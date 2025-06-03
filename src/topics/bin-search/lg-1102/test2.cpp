/**
 * 二分
 */
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        auto end = std::upper_bound(a.begin(), a.end(), a[i] + c) - a.begin();
        auto start = std::lower_bound(a.begin(), a.end(), a[i] + c) - a.begin();
        ans += end - start;
    }
    std::cout << ans << std::endl;
}