/**
 * @see https://codeforces.com/contest/2014/problem/B
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    i64 ans = k * (n - k + 1 + n) / 2;
    std::cout << (ans & 1 ? "No" : "Yes") << std::endl;
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