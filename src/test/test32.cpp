#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    int max = 28 - k;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x <= max) {
            ++cnt;
        }
    }
    std::cout << cnt << std::endl;
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