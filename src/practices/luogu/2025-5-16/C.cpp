#include <bits/stdc++.h>

using i64 = long long;
const int N = 1e6 + 5;
i64 pre[N];

int main() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        i64 x;
        std::cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    i64 ans = 0;
    for (int i = 0; i < n - k; ++i) {
        ans = std::max(ans, pre[i + k] - pre[i]);
    }
    std::cout << (pre[n - 1] - pre[0]) - ans << std::endl;
}