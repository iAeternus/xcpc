/**
 * 记忆化递归
 */
#include <bits/stdc++.h>

using ll = long long;
const int MOD = 1e9 + 7;

ll fib1(int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return (fib1(n - 1) + fib1(n - 2)) % MOD;
}

const int N = 42;
ll fib[N];

ll fib2(int n) {
    if (fib[n]) return fib[n];
    if (n == 1 || n == 2)
        return fib[n] = 1;
    else
        return fib[n] = (fib2(n - 1) + fib2(n - 2)) % MOD;
}

int main() {
    for (int i = 1; i <= N; ++i) {
        std::cout << fib1(i) << ' ' << fib2(i) << std::endl;
    }
}