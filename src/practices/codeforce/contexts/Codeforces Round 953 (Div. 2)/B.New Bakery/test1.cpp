/*
https://codeforces.com/contest/1978/problem/B

超时
*/
#include <bits/stdc++.h>

using ll = long long;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        ll n, a, b;
        std::cin >> n >> a >> b;

        if (b <= a) {
            std::cout << n * a << std::endl;
            continue;
        }

        ll fmin = std::min(n, b);
        ll fmax = -1;
        for (int k = 0; k <= fmin; ++k) {
            ll first = ((2 * b - k + 1) * k) / 2;
            ll sec = (n - k) * a;
            fmax = std::max(fmax, first + sec);
        }

        std::cout << fmax << std::endl;
    }
}