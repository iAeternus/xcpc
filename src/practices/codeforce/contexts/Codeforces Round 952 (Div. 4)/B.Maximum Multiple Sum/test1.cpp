/*
https://codeforces.com/contest/1985/problem/B
*/
#include <bits/stdc++.h>

using ll = long long;
ll n;

ll func(ll x) {
    ll tmp = n / x;
    return (((1 + tmp) * tmp) / 2) * x;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        ll fmax = -1, ans;
        for (int x = 2; x <= n; ++x) {
            ll tmp = func(x);
            if (tmp > fmax) {
                fmax = tmp;
                ans = x;
            }
        }
        std::cout << ans << std::endl;
    }
}