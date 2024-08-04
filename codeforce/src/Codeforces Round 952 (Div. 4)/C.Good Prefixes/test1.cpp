/*
https://codeforces.com/contest/1985/problem/C
*/
#include <bits/stdc++.h>

using ll = long long;
const int N = 2e5 + 7;
ll a[N], n;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int ans = 0;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        if (a[0] == 0) { // 直接算前缀
            ++ans;
        }
        ll fmax = a[0], prefix = a[0];
        for (int i = 1; i < n; ++i) {
            fmax = std::max(fmax, a[i]);
            prefix += a[i];
            if (prefix - fmax == fmax) {
                ++ans;
            }
        }

        std::cout << ans << std::endl;
    }
}