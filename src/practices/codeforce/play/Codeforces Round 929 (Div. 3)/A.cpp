/**
 * @see https://codeforces.com/contest/1933/problem/A
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        ans += abs(a);
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