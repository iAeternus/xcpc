/**
 * @see https://www.luogu.com.cn/problem/T593827
 * dp[i]: 从i开始的最大价值
 * dp[i] = max(dp[i + 1], dp[k] + v[i]) // 不选i/选择i然后选择k
 */
#include <bits/stdc++.h>

using i64 = long long;
const int N = 105;

int x[N], v[N], d[N];
i64 dp[N];

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> x[i] >> v[i] >> d[i];
    }

    dp[n - 1] = v[n - 1];
    for(int i = n - 1; i >= 0; --i) {
        auto k = std::lower_bound(x + i + 1, x + n, x[i] + d[i]) - x;
        dp[i] = std::max(dp[i + 1], dp[k] + v[i]);
    }

    std::cout << dp[0] << std::endl;
}