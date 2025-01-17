/**
 * @see https://codeforces.com/contest/2040/problem/A
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), cnt(k);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i] %= k;
        cnt[a[i]]++;
    }
    for(int i = 0; i < n; ++i) {
        if(cnt[a[i]] == 1) {
            std::cout << "YES" << std::endl;
            std::cout << i + 1 << std::endl;
            return;
        }
    }
    std::cout << "NO" << std::endl;
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