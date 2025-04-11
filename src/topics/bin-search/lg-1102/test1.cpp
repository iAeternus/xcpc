/**
 * @see https://www.luogu.com.cn/problem/P1102
 * hash
 */
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> a(n);
    std::map<int, int> mp;
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
        ++mp[a[i]];
        a[i] -= c; // b
    }
    i64 ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += mp[a[i]];
    }
    std::cout << ans << std::endl;
}