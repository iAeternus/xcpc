/**
 * @see https://codeforces.com/contest/2014/problem/C
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    i64 sum = 0LL;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }
    if (n <= 2) {
        std::cout << -1 << std::endl;
        return;
    }
    std::sort(a.begin(), a.end());
    std::cout << std::max(0LL, 2LL * n * a[n >> 1] + 1LL - sum) << std::endl;
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