/**
 * @see https://codeforces.com/contest/2020/problem/A
 */
#include <bits/stdc++.h>

using ll = long long;

ll fast_pow(ll a, ll n, ll m) {
    ll ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        n >>= 1;
    }
    return ans;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;

        if (k == 1) {
            std::cout << n << std::endl;
            continue;
        }

        int ans = 0;
        for (int x = 30; x >= 0; --x) {
            ll tmp = fast_pow(k, x, LONG_LONG_MAX);
            if (tmp <= n && tmp > 0) { // tmp > 0 不加会 RE
                int cnt = n / tmp;
                ans += cnt;
                n -= (cnt * tmp);
            }
        }

        std::cout << ans << std::endl;
    }
}