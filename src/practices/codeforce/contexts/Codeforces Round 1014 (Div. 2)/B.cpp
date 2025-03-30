#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::string a, b;
    std::cin >> n >> a >> b;
    int cnt1 = 0; // a的奇数位 + b的偶数位
    int cnt2 = 0; // b的奇数位 + a的偶数位
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            cnt1 += a[i] == '1';
            cnt2 += b[i] == '1';
        } else {
            cnt1 += b[i] == '1';
            cnt2 += a[i] == '1';
        }
    }
    std::cout << (cnt1 > (n + 1) / 2 || cnt2 > n / 2 ? "NO" : "YES") << std::endl;
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