/**
 * @see https://codeforces.com/contest/1542/problem/B
 * 
 * n = a^p + qb
 */
#include <bits/stdc++.h>

using i64 = long long;

bool solve() {
    i64 n, a, b;
    std::cin >> n >> a >> b;
    if (a == 1) {
        // n = 1 + qb
        return (n - 1) % b == 0;
    }
    // n = a^p + qb
    for (i64 num = 1; num <= n; num *= a) {
        if ((n - num) % b == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        std::cout << (solve() ? "YES" : "NO") << std::endl;
    }

    return 0;
}