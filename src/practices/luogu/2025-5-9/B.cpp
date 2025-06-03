#include <bits/stdc++.h>

const int N = 2e4 + 10;
int dp[2][N], l[N], r[N], len[N];

int dis(int a, int b) {
    return std::abs(a - b);
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> l[i] >> r[i];
        len[i] = r[i] - l[i];
    }

    dp[0][1] = r[1] - 1 + len[1];
    dp[1][1] = r[1] - 1;
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = std::min(dp[0][i - 1] + dis(r[i], l[i - 1]), dp[1][i - 1] + dis(r[i - 1], r[i])) + len[i] + 1;
        dp[1][i] = std::min(dp[0][i - 1] + dis(l[i - 1], l[i]), dp[1][i - 1] + dis(r[i - 1], l[i])) + len[i] + 1;
    }

    std::cout << std::min(dp[0][n] + dis(n, l[n]), dp[1][n] + dis(n, r[n])) << std::endl;
}