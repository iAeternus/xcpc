/**
 * @see https://www.luogu.com.cn/problem/P1890
 */
#include <bits/stdc++.h>

const int N = 1e3 + 5;
int a[N], Gcd[std::__lg(N) + 1][N];

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

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        Gcd[0][i] = a[i];
    }
    for(int i = 1; i <= std::__lg(n); ++i) {
        for(int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Gcd[i][j] = gcd(Gcd[i - 1][j], Gcd[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int query(int l, int r) {
    int s = std::__lg(r - l + 1);
    return gcd(Gcd[s][l], Gcd[s][r - (1 << s) + 1]);
}

int main() {
    int n = read(), m = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    init(n);

    while(m--) {
        int l = read(), r = read();
        std::cout << query(l, r) << std::endl;
    }
}