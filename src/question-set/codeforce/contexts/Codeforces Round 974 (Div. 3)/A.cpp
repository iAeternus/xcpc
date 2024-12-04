/**
 * @see https://codeforces.com/contest/2014/problem/A
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    int ans = 0, gold = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        std::cin >> a;
        if (a >= k) {
            gold += a;
        } else if (a == 0 && gold > 0) {
            ++ans;
            --gold;
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