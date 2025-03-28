/**
 * @see https://www.luogu.com.cn/problem/P2880
 */
#include <bits/stdc++.h>

const int N = 5e4 + 3;
int Min[N][17], Max[N][17];
int Log[N];

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

int main() {
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int x = read();
        Max[i][0] = x;
        Min[i][0] = x;
    }

    for (int i = 2; i <= n; ++i) {
        Log[i] = Log[i >> 1] + 1;
    }

    for (int i = 1; i <= 16; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Max[j][i] = std::max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
            Min[j][i] = std::min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
        }
    }

    while (q--) {
        int l = read(), r = read();
        int s = Log[r - l + 1];
        int ma = std::max(Max[l][s], Max[r - (1 << s) + 1][s]);
        int mi = std::min(Min[l][s], Min[r - (1 << s) + 1][s]);
        std::cout << ma - mi << std::endl;
    }
}