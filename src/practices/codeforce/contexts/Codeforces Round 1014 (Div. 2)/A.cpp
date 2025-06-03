#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int mi = INT_MAX, ma = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        mi = std::min(mi, x);
        ma = std::max(ma, x);
    }
    std::cout << ma - mi << std::endl;
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