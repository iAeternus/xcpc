/**
 * @see https://www.luogu.com.cn/problem/P12836
 * TODO WA，不能修改a[i]，会爆 long long
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    i64 ans = 0;
    for(int i = 1; i < n; ++i) {
        if(a[i] >= a[i - 1]) continue;

        i64 tmp = a[i - 1] / a[i];
        if(tmp == 1) {
            ++ans;
            a[i] <<= 1LL;
        } else {
            i64 cnt = ceil(log2(tmp));
            ans += cnt;
            a[i] = a[i] * (1LL << cnt);
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}