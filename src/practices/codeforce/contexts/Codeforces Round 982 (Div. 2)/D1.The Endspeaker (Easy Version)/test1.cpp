/**
 * @see https://codeforces.com/contest/2027/problem/D1
 */
#include <bits/stdc++.h>

const int N = 3e5 + 7;
int a[N], b[N];
int prefix[N];
int dp[N][1000];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (i) {
                prefix[i] = prefix[i - 1] + a[i];
            } else {
                prefix[i] = a[0];
            }
        }
        for (int j = 0; j < m; ++j) {
            std::cin >> b[j];
        }

        if (a[0] > b[0]) {
            std::cout << -1 << std::endl;
            continue;
        }

        int type_1 = INT_MAX, type_2 = INT_MAX;
        int k = 1;
        int a_start = 0;
        for (int i = n - 1; i >= a_start; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (k < m && a_start != n - 1) {
                    type_1 = dp[i][j + 1];
                }

                auto it = std::upper_bound(prefix, prefix + n, b[k]);
                int d = std::distance(prefix, it);
                type_2 = dp[i + d][j] + m - k;
                dp[i][j] = std::min(type_1, type_2);

                if (type_2 < type_1) {
                    dp[i][j] = type_2;
                    a_start = d;
                } else {
                    dp[i][j] = type_1;
                }
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < k; ++j) {
            ans = std::min(ans, dp[0][j]);
        }

        std::cout << ans << std::endl;
    }
}