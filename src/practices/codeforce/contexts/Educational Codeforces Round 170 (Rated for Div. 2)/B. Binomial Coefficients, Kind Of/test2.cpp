#include <bits/stdc++.h>

using ll = long long;
const int MOD = 1e9 + 7;

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
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
    }

    for (int i = 0; i < t; ++i) {
        int k;
        std::cin >> k;
        std::cout << qpow(2, k, MOD) << std::endl;
    }
}