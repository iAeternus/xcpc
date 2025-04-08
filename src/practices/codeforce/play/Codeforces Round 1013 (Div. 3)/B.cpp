#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::ranges::sort(a, std::greater<>());
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        ++cnt;
        if (a[i] * cnt >= x) {
            cnt = 0;
            ans++;
        }
    }
    std::cout << ans << std::endl;
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