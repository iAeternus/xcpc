/**
 * @see https://www.lanqiao.cn/problems/19982/learning/?contest_id=216
 */
#include <bits/stdc++.h>

using ll = long long;
ll mod = 1e9 + 7;

ll qpow(ll a, ll b, ll mod) {
    ll ans = 1;
    a = a % mod;
    while (b) {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b = b >> 1;
    }
    return ans;
}

int main() {
    ll l, r, sum, first, second;
    std::cin >> l >> r;
    sum = 0;
    first = qpow(l, l, mod);
    for (int i = l + 1; i <= r; i++) {
        second = qpow(i, i, mod);
        sum = (sum + (first * second) % mod) % mod;
        first = second;
    }
    std::cout << sum << std::endl;
}