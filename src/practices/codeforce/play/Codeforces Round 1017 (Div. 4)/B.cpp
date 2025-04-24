#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, l, r;
    std::cin >> n >> m >> l >> r;
    int cnt = n - m;
    while(l + 1 <= 0 && cnt > 0) {
        ++l;
        cnt--;
    }
    while(r - 1 >= 0 && cnt > 0) {
        --r;
        --cnt;
    }
    std::cout << l << ' ' << r << std::endl;
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