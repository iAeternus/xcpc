/*
sample input
3
1
2
3

sample output
-1 -1
3 6
4 12
*/
#include <bits/stdc++.h>

using ll = long long;

void solve() {
    ll n;
    std::cin >> n;

    for (ll k = n - 1; k >= 1; --k) {
        ll x = n - k;
        ll y = n - (n * (n / k));
        if (x >= 1 && x <= 1e18 && y >= 1 && y <= 1e18) {
            std::cout << x << ' ' << y << std::endl;
            return;
        }
    }
    std::cout << "-1 -1" << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}