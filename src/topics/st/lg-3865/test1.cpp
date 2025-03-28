/**
 * @see https://www.luogu.com.cn/problem/P3865
 */
#include <bits/stdc++.h>

const int N = 1e5 + 3;
int st[20][N]; // 第二维足够处理1e5的数据（2^17 > 1e5）
int lg[N];

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

void init_log() {
    lg[1] = 0, lg[2] = 1;
    for (int i = 3; i < N; ++i) {
        lg[i] = lg[i >> 1] + 1;
    }
}

int main() {
    init_log();
    int n = read(), m = read();

    for (int i = 0; i < n; ++i) {
        st[0][i] = read();
    }

    for (int j = 1; (1 << j) <= n; ++j) {
        int k = 1 << (j - 1);
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            // st[i][j] = op(st[i][j - 1], st[i + k][j - 1])
            st[j][i] = std::max(st[j - 1][i], st[j - 1][i + k]);
        }
    }

    while (m--) {
        int l = read() - 1, r = read() - 1;
        int s = lg[r - l + 1];
        printf("%d\n", std::max(st[s][l], st[s][r - (1 << s) + 1]));
    }
}
