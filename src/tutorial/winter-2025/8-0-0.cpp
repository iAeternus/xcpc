#include <bits/stdc++.h>

// fib(i) = fib(i - 1) + fib(i - 2) // a = 1 b = 1
int fib(int i) {
    if (i == 1 || i == 2) {
        return 1;
    }
    return fib(i - 1) + fib(i - 2);
}

int fib2(int n) {
    std::vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    for (int i = 1; i < 50; ++i) {
        std::cout << fib(i) << std::endl;
    }
}