#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int x, y;
    std::cin >> x >> y;
    if (y % 2 == 0) {
        std::cout << "NO" << std::endl;
        return;
    }
    std::cout << (abs(y / 2 - x) % 2 == 0 ? "YES" : "NO") << std::endl;
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