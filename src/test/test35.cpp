#include <bits/stdc++.h>

using i64 = long long;

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // int t;
    // std::cin >> t;

    // while(t--) {
    //     solve();
    // }

    i64 n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (i64 i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    i64 min_ans = LONG_LONG_MAX;
    for (i64 i = 0; i < n; ++i) {
        i64 ans = 0, cur = 0;
        for (i64 j = i - 1; j >= 0; --j) {
            ans += cur / a[j] + 1LL; // 减
            cur = (cur / a[j] + 1LL) * a[j];
        }
        cur = 0;
        for (i64 j = i + 1; j < n; ++j) {
            ans += (cur / a[j] + 1LL); // 加
            cur = (cur / a[j] + 1LL) * a[j];
        }
        min_ans = std::min(min_ans, ans);
    }
    std::cout << min_ans << std::endl;

    return 0;
}