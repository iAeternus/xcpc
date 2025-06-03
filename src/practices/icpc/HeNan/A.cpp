#include <bits/stdc++.h>

using i64 = long long;
std::vector<i64> pw(20);

void solve() {
    i64 n, d;
    std::cin >> n >> d;

    int i = 0;
    while(pw[i] < n) ++i;
    i64 num = 123456789LL * pw[i + 1] + d * pw[i];
    i64 tmp = (pw[i] - num % n) % pw[i];
    std::cout << (num + tmp) % n << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    pw[0] = 1;
    for(int i = 1; i <= 18; ++i) {
        pw[i] = pw[i - 1] * 10;
    }

    while (t--) {
        solve();
    }

    return 0;
}