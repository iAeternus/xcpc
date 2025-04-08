#include <bits/stdc++.h>

using i64 = long long;
int n, m, k;

bool check(int d) {
    return m / (d + 1) * d + m % (d + 1) < (k + n - 1) / n;
}

void solve() {
    std::cin >> n >> m >> k;
    int l = 1, r = m, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    std::cout << l << std::endl;
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