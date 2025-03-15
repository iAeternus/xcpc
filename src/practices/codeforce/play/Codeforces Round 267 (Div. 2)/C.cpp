/**
 * @see https://codeforces.com/problemset/problem/467/C
 * 
 * dp[i][j]: 区间[1...i]中选择了j个子数组，最大和为dp[i][j]
 * 考虑最后一个区间[lk, rk]，其只有两种情况
 * 1. rk = n: dp[i - m][j - 1] + sum(i - m, i)
 * 2. rk < n: dp[i - 1][j]
 */
#include <bits/stdc++.h>

using i64 = long long;
const int N = 5e3 + 5;
i64 a[N], prefix[N];
i64 dp[N][N];

// i64 max(i64 a, i64 b, i64 c) {
//     return std::max(a, std::max(b, c));
// }

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    // i64 ans = 0;
    for(int i = m; i <= n; ++i) {
        i64 sum = prefix[i] - prefix[i - m];
        for(int j = 1; j <= k; ++j) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i - m][j - 1] + sum);
        }
        // ans = std::max(ans, dp[i][k]);
    }
    std::cout << dp[n][k] << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // int t;
    // std::cin >> t;

    // while(t--) {
        solve();
    // }

    return 0;
}