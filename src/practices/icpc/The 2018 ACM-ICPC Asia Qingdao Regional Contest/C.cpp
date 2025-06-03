/**
 * @see https://vjudge.net/contest/268518#problem/C
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s, t, d;
    std::cin >> s >> t;
    for (int i = 0; i < n; ++i) {
        d.push_back(s[i] == t[i] ? '0' : '1'); // ^
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] == '1' && d[i + 1] != '1') {
            ++k;
        }
    }
    if (k == 0) {
        std::cout << (n + 1) * n / 2 << std::endl;
    } else if (k == 1) {
        std::cout << 2 * (n - 1) << std::endl;
    } else if (k == 2) {
        std::cout << 6 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
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