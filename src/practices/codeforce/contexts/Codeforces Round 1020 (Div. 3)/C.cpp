#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n), b(n);
    i64 min_ = LONG_LONG_MAX, max_ = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        min_ = std::min(min_, a[i]);
        max_ = std::max(max_, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    i64 sum = 0;
    bool fst = true;
    for (int i = 0; i < n; ++i) {
        if(b[i] != -1) {
            if(fst) {
                sum = a[i] + b[i];
                fst = false;
            } else {
                if(sum != a[i] + b[i]) {
                    std::cout << 0 << std::endl;
                    return;
                }
            }
        }
    }

    if (!fst) {
        if (max_ > sum || sum - min_ > k) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
        return;
    }

    if (max_ - min_ > k) {
        std::cout << 0 << std::endl;
        return;
    }

    std::cout << min_ + k - max_ + 1 << std::endl;
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