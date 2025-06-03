#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int max_elem = -1, min_elem = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        int a;
        std::cin >> a;
        max_elem = std::max(max_elem, a);
        min_elem = std::min(min_elem, a);
    }
    std::cout << (max_elem - min_elem) * (n - 1) << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}