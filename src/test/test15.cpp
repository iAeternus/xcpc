/*
7
2 1 1 3 1 1 4

7
1 2 3 1 1 2 1

7
1 2 1 2 1 3 4
*/
#include <bits/stdc++.h>

const int N = 1e6 + 3;
int a[N], dp[2][N];  // 0-选1个 1-选2个

int num[19];

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if(n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    dp[0][0] = 1;

    bool flag = true;  // 连续
    num[a[0]]++;
    for (int i = 1; i < n; ++i) {
        if (num[a[i]] == 0 && flag) {
            dp[0][i] = dp[0][i - 1] + 1;
        } else {
            dp[0][i] = dp[0][i - 1];
            flag = false;
        }
        num[a[i]]++;
    }

    if(n == dp[0][n - 1]) {
        std::cout << dp[0][n - 1] << std::endl;
        return 0;
    }

    memset(num, 0, sizeof(num));

    for(int i = 0; i < dp[0][n - 1]; ++i) {
        num[a[i]]++;
    }

    for (int i = dp[0][n - 1]; i < n; ++i) {
        if (num[a[i]] == 0) {
            dp[1][i] = std::max(dp[1][i - 1], dp[0][i - 1] + 1);
            if(num[a[i - 1]] == 1) {
                dp[1][i]++;
            }
        } else {
            dp[1][i] = std::max(dp[1][i - 1], dp[0][i - 1]);
        }
        num[a[i]]++;
    }

    // for (int i = 0; i < 2; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         std::cout << dp[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }

    std::cout << dp[1][n - 1] << std::endl;
}