/**
 * @see https://codeforces.com/contest/2040/problem/B
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int k = 1, ans = 1;
    while(k < n) {
        k = (k + 1) * 2;
        ans++;
    }
    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}