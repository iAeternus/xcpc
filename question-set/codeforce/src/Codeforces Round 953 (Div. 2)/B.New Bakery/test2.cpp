/*
https://codeforces.com/contest/1978/problem/B
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
        } else {
            ll t = b - a;
            if (t >= n) {
                std::cout << (b + b - n + 1) * n / 2 << std::endl;
            } else {
                std::cout << (b + a) * (b - a + 1) / 2 + (n - (b - a) - 1) * a << std::endl;
            }
        }
    }
}