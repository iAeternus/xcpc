/**
 * @see https://www.luogu.com.cn/problem/P12833
 */
#include <bits/stdc++.h>

using i64 = long long;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
i64 f[N], g[N], r[N];

void init() {
    f[1] = 0, f[2] = 1; // 1
    for(int i = 3; i < N; ++i) {
        f[i] = (f[i - 1] + f[i - 2]) % M;
    }

    g[1] = 1, g[2] = 0; // 0
    for(int i = 3; i < N; ++i) {
        g[i] = (g[i - 1] + g[i - 2]) % M;
    }

    r[1] = r[2] = r[3] = 0;
    for(int i = 4; i < N; ++i) {
        r[i] = ((r[i - 1] + r[i - 2]) % M + (f[i - 2] * g[i - 1]) % M) % M;
    }
}

void solve() {
    int n;
    std::cin >> n;

    if(n == 1 || n == 2 || n == 3) {
        std::cout << 0 << std::endl;
        return;
    }

    std::cout << r[n] << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    init();

    while (t--) {
        solve();
    }

    return 0;
}