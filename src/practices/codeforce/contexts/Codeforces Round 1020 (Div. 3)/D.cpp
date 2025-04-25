#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 3;
int a[N];
int Max[std::__lg(N) + 1][N], Min[std::__lg(N) + 1][N];
int b[N];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        Max[0][i] = b[i];
        Min[0][i] = b[i];
    }
    for (int i = 1; i <= std::__lg(n); ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Max[i][j] = std::max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
            Min[i][j] = std::min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int query_max(int l, int r) {
    int s = std::__lg(r - l + 1);
    return std::max(Max[s][l], Max[s][r - (1 << s) + 1]);
}

int query_min(int l, int r) {
    int s = std::__lg(r - l + 1);
    return std::min(Min[s][l], Min[s][r - (1 << s) + 1]);
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        std::cin >> b[i];
    }

    std::vector<int> l_max(n + 1); // 从左到右a匹配最多b的前缀长度
    int cur_b = 0;
    for (int i = 1; i <= n; i++) {
        if (cur_b < m && a[i] >= b[cur_b + 1]) {
            cur_b++;
        }
        l_max[i] = cur_b;
    }
    if (l_max[n] == m) {
        std::cout << 0 << std::endl;
        return;
    }

    std::vector<int> r_max(n + 1); // 从右到左a匹配最多b的后缀长度
    cur_b = m - 1;
    for (int i = n; i >= 1; i--) {
        if (cur_b >= 0 && a[i] >= b[cur_b + 1]) {
            cur_b--;
        }
        r_max[i] = (m - 1 - cur_b);
    }

    init(m);

    int ans = INT_MAX;
    for (int pos = 0; pos <= n; pos++) {
        int l_cnt = pos == 0 ? 0 : l_max[pos];
        int r_cnt = pos == n ? 0 : r_max[pos + 1];

        int A = std::max(1, m - r_cnt);
        int B = std::min(m, l_cnt + 1);
        if (A > B) continue;

        int min_b = query_min(A, B);
        if (min_b < ans) {
            ans = min_b;
        }
    }

    std::cout << (ans == INT_MAX ? -1 : ans) << std::endl;
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