/**
 * @see https://codeforces.com/problemset/problem/622/C
 * 
 * O(nlogn + m)
 */
#include <bits/stdc++.h>

const int N = 2e5 + 3;
int a[N], Max[std::__lg(N) + 1][N], Min[std::__lg(N) + 1][N];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        Max[0][i] = i;
        Min[0][i] = i;
    }
    for (int i = 1; i <= std::__lg(n); ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Max[i][j] = a[Max[i - 1][j]] > a[Max[i - 1][j + (1 << (i - 1))]] ? Max[i - 1][j] : Max[i - 1][j + (1 << (i - 1))];
            Min[i][j] = a[Min[i - 1][j]] < a[Min[i - 1][j + (1 << (i - 1))]] ? Min[i - 1][j] : Min[i - 1][j + (1 << (i - 1))];
        }
    }
}

int query(int l, int r) {
    int s = std::__lg(r - l + 1);
    return a[Max[s][l]] > a[Max[s][r - (1 << s) + 1]] ? Max[s][l] : Max[s][r - (1 << s) + 1];
}

int query2(int l, int r) {
    int s = std::__lg(r - l + 1);
    return a[Min[s][l]] < a[Min[s][r - (1 << s) + 1]] ? Min[s][l] : Min[s][r - (1 << s) + 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    init(n);

    while (m--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        int max_idx = query(l, r), min_idx = query2(l, r);
        if (a[max_idx] == a[min_idx] && a[max_idx] == x) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << (a[min_idx] != x ? min_idx : max_idx) << std::endl;
        }
    }
}