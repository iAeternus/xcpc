#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    int zero = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == 0) {
            ++zero;
        }
    }

    if (m == n) {
        std::cout << "Richman\n";
        return;
    } else if (zero > m) {
        std::cout << "Impossible\n";
        return;
    }

    i64 sum = 0;
    m -= zero;
    int i;
    for (i = 0; m > 0; ++i) {
        if (a[i] == 0) continue;
        sum += a[i];
        m--;
    }
    int min_p = INT_MAX;
    for (; i < n; ++i) {
        if (a[i] > 0) {
            min_p = std::min(min_p, a[i]);
        }
    }
    std::cout << sum + min_p - 1 << std::endl;
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