#include <bits/stdc++.h>

using i64 = long long;
const int N = 2e5 + 5;
const int K = 20; // log2(N)约等于18
i64 st[K][N];
int len = 0;

/**
 * 动态追加的st表
 */
void insert(int val) {
    len++;
    st[0][len] = val;
    for (int s = 1; (1 << s) <= len; s++) {
        int start = len - (1 << s) + 1;
        if (start < 1) break;
        st[s][start] = std::max(st[s - 1][start], st[s - 1][start + (1 << (s - 1))]);
    }
}

int query_max(int l, int r) {
    int s = std::__lg(r - l + 1);
    return std::max(st[s][l], st[s][r - (1 << s) + 1]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m, d, t = 0;
    std::cin >> m >> d;
    while (m--) {
        char c;
        i64 n;
        std::cin >> c >> n;
        if (c == 'A') {
            n = (n + t) % d;
            insert(n);
        } else {
            int l = len - n + 1;
            t = query_max(l, len);
            std::cout << t << '\n';
        }
    }
}
