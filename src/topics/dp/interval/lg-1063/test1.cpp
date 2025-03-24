#include <bits/stdc++.h>

const int N = 1e2 + 3;
int a[N << 1];
int dp[N << 1][N << 1];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }

    int nn = n << 1;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= nn; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = std::max(ans, dp[i][i + n - 1]);
    }
    std::cout << ans << std::endl;
}