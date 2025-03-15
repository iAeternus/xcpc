#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int m, a, b, c;
    std::cin >> m >> a >> b >> c;
    int ans = std::min(m, a) + std::min(m, b);
    if(m > a) {
        if(c < m - a) {
            ans += c;
            c = 0;
        } else {
            ans += (m - a);
            c -= (m - a);
        }
    }
    if(m > b) {
        ans += std::min(c, m - b);
    }
    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}