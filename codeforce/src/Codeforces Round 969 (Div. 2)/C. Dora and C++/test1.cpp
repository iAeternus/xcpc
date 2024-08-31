/**
 * @see https://codeforces.com/contest/2007/problem/C
 */
#include <bits/stdc++.h>

using ll = long long;
const int N = 1e5 + 3;
ll c[N];
ll d[N];

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        ll n, a, b;
        std::cin >> n >> a >> b;
        int i;
        for (i = 0; i < n; i++) {
            std::cin >> c[i];
        }
        int g = gcd(a, b);
        for (i = 0; i < n; i++) {
            d[i] = c[i] % g;
        }
        std::sort(d, d + n);
        ll fmin = d[n - 1] - d[0];
        for (i = 0; i < n - 1; i++) {
            if (d[i + 1] != d[i]) {
                fmin = std::min(fmin, g + d[i] - d[i + 1]);
            }
        }
        std::cout << fmin << "\n";
    }
}