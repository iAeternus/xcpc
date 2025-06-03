#include <bits/stdc++.h>

const int N = 5e6 + 10;
int a[N], d[N];

int main() {
    int n, p;
    std::cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        d[i] = a[i] - a[i - 1];
    }

    while (p--) {
        int x, y, z;
        std::cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }

    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        d[i] += d[i - 1];
        ans = std::min(ans, d[i]);
    }
    std::cout << ans << std::endl;
}