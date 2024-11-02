/**
 * @see https://codeforces.com/contest/2027/problem/B
 */
#include <bits/stdc++.h>

using ll = long long;
const int N = 2e3 + 5;
ll a[N];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        ll t_min = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            long long t = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i]) {
                    t++;
                }
            }
            t_min = std::min(t_min, t);
        }
        std::cout << t_min << std::endl;

        // int num_max = 0, num_max_idx = -1;
        // for (int i = n - 1; i >= 0; --i) {
        //     if (a[i] > num_max) {
        //         num_max = a[i];
        //         num_max_idx = i;
        //     }
        // }

        // if (num_max_idx == 0) {
        //     std::cout << 0 << std::endl;
        //     continue;
        // }

        // int sec_max = 0, sec_max_idx = -1;
        // for (int i = num_max_idx - 1; i >= 0; --i) {
        //     if (a[i] > sec_max) {
        //         sec_max = a[i];
        //         if (num_max > sec_max) {
        //             sec_max_idx = i;
        //         } else {
        //             sec_max = 0;
        //         }
        //     }
        // }

        // int ans = sec_max_idx;
        // if (num_max != sec_max) {
        //     ans++;
        // }
        // std::cout << ans << std::endl;
    }
}