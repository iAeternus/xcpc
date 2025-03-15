#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int l, r;
    std::cin >> l >> r;
    if (l == 1 && r == 1) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << r - l << std::endl;
    }
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