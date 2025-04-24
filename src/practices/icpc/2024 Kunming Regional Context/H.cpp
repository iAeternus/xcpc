/*
5
1 1
0 1
8 2
1 0
1 1
0 1
-1 1
-1 0
-1 -1
0 -1
1 -1
4 2
-1 1
0 1
0 2
1 1
4 2
-1000000000 0
-998244353 1
998244353 1
1000000000 0
3 1
0 1
0 2
0 -1

*/
#include <bits/stdc++.h>

using i64 = long long;
const double PI = acos(-1.0);

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<double> v(n << 1);
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        double angle = atan2(y, x);
        if (angle < 0) {
            angle += 2 * PI;
        }
        v[i] = angle;
        v[i + n] = angle + 2 * PI;
    }

    std::sort(v.begin(), v.end());

    if (k == n) {
        std::cout << 2 * PI << std::endl;
        return;
    }

    double ans = 0;
    int n2 = n << 1;
    for (int i = 0; i < n2 - k; ++i) {
        ans = std::max(ans, abs(v[i + k] - v[i]));
    }
    std::cout << std::min(ans, 2 * PI) << std::endl;
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