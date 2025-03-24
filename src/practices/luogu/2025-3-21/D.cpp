#include <bits/stdc++.h>

using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    i64 ans = a[n - 1] * a[n - 1];
    int l = 0, r = n - 1;
    while(l < r) {
        ans += (a[r] - a[l]) * (a[r] - a[l]);
        --r;
        ans += (a[r] - a[l]) * (a[r] - a[l]);
        ++l;
    }
    std::cout << ans << std::endl;
}