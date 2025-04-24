/**
 * @see https://vjudge.net/contest/268518#problem/E
 */
#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 3;
int n, a[N];
i64 m, d[N];

bool check(i64 d_min) {
    std::fill(d, d + n + 3, 0LL);
    i64 step = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i] < d_min) {
            i64 t = ((d_min - d[i]) + a[i] - 1) / a[i];
            step += (t << 1) - 1;
            if (step > m) return false;
            d[i + 1] += a[i + 1] * (t - 1);
        } else {
            ++step;
        }
    }
    return true;
}

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    i64 l = 0, r = 1e18;
    while (l < r) {
        i64 mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << r << std::endl;
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