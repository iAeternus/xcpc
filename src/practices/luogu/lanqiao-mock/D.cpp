/**
 * @see https://www.luogu.com.cn/problem/P1478
 * 01背包
 * 背包容量为s，物品价值为数量，体积为y
 * dp[j]: 背包容量为j时，最多能摘dp[j]个苹果
 * if x <= a + b dp[j] = max(dp[j], dp[j - y[i]] + 1)
 */
#include <bits/stdc++.h>

const int N = 5e3 + 3;
int x[N], y[N], dp[N];

int main() {
    int n, s, a, b;
    std::cin >> n >> s >> a >> b;
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i) {
        if (x[i] > a + b) continue;
        for (int j = s; j >= y[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - y[i]] + 1);
        }
    }

    std::cout << dp[s] << std::endl;
}