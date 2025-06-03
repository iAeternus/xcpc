/**
 * @see https://codeforces.com/problemset/problem/1840/C
 */
#include <bits/stdc++.h>

using ll = long long;
const int N = 2e5 + 3;
ll a[N];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        ll n, k, q;
        std::cin >> n >> k >> q;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }

        ll cnt = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] <= q) {
                ++cnt;
            } else {
                cnt = 0;
            }

            if (cnt >= k) {
                ans += (cnt - k + 1);
            }
        }

        std::cout << ans << std::endl;
    }
}