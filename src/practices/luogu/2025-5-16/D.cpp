#include <bits/stdc++.h>

using i64 = long long;
const int N = 2e5 + 3;
i64 n, m;
i64 a[N], b[N];

bool check(i64 mid) {
    i64 sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (mid - a[i] > b[i]) return false;
        sum += std::max(mid - a[i], 0LL);
    }
    return sum < m;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];
    }

    i64 l = 0, r = LONG_LONG_MAX;
    while (l < r) {
        i64 mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << r << std::endl;
}