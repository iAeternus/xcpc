#include <bits/stdc++.h>

using i64 = long long;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    int sq = std::sqrt(num);
    for (int i = 2; i <= sq; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int x, k;
    std::cin >> x >> k;
    std::cout << (isPrime(x) ? "YES" : "NO") << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}