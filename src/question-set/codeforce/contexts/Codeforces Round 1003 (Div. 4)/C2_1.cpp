#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a, b;
    a.push_back(INT_MIN);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        b.push_back(x);
    }

    std::sort(b.begin(), b.end());
    for (int i = 1; i < a.size(); ++i) {
        auto bj = std::lower_bound(b.begin(), b.end(), a[i]);
        if (a[i - 1] <= a[i]) {
            if (bj != b.end()) {
                a[i] = std::min(a[i], *bj - a[i]);
            } else {
                if (a[i - 1] <= b[b.size() - 1] - a[i]) {
                    a[i] = b[b.size() - 1] - a[i];
                }
            }
        } else {
            if (bj != b.end()) {
                a[i] = *bj - a[i];
            } else {
                if (a[i - 1] <= b[b.size() - 1] - a[i]) {
                    a[i] = b[b.size() - 1] - a[i];
                } else {
                    std::cout << "NO" << std::endl;
                }
            }
        }
    }
    std::cout << "YES" << std::endl;
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