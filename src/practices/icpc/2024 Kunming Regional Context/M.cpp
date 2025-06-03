/**
 * 对角线计算：每个副对角线满足i + j = s（s为对角线编号）
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int cur = 1;
    std::vector a(n, std::vector<int>(m));
    for (int s = 0; s <= n + m - 2; ++s) {
        int i_start = std::max(0, s - m + 1);
        int i_end = std::min(n - 1, s);
        for (int i = i_start; i <= i_end; ++i) {
            int j = s - i;
            a[i][j] = cur++;
        }
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }
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