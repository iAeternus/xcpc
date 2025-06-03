#include <bits/stdc++.h>

const int N = 1e3 + 5;
int dp[N];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int half_i = i >> 1;
        for (int j = 1; j <= half_i; ++j) {
            dp[i] += dp[j];
        }
        dp[i] += 1;
    }
    std::cout << dp[n] << std::endl;
}