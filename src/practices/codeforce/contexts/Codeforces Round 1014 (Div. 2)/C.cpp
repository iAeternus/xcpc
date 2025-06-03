#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x & 1) {
            a.push_back(x);
        } else {
            b.push_back(x);
        }
    }

    std::ranges::sort(a, std::greater<>());
    std::ranges::sort(b, std::greater<>());

    if (a.empty()) {
        std::cout << b[0] << std::endl;
        return;
    } else if (b.empty()) {
        std::cout << a[0] << std::endl;
        return;
    }

    i64 ans = std::accumulate(b.begin(), b.end(), 0LL) + a[0];
    for (int i = 1; i < a.size(); ++i) {
        ans += a[i] - 1;
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