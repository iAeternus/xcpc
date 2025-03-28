/**
 * st表用于解决可重复贡献问题
 * 设有一个二元运算 op(x, y) ，满足 op(a, a) = a，则称op为可重复贡献的
 * 显然最大值、最小值、最大公因数、最小公倍数、按位或、按位与都符合这个条件
 * 
 * std::__lg(x) 函数时间复杂度为 O(1)
 */
#include <bits/stdc++.h>

const int N = 5e4 + 3;
// 原数组a, 最大值st表Max，最小值st表Min
// 这里为了内存局部性将较小者作为行数
int a[N], Max[std::__lg(N) + 1][N], Min[std::__lg(N) + 1][N];

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

/**
 * 初始化st表
 * st[i][j]: 表示闭区间 [i, i + 2^j - 1] 的操作结果
 * 显然 st[i][0] = ai
 * 
 * st[i][j] = op( st[i][j - 1], st[i + 2^(j-1)][i - 1] )
 */
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        Max[0][i] = a[i];
        Min[0][i] = a[i];
    }
    for (int i = 1; i <= std::__lg(n); ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Max[i][j] = std::max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
            Min[i][j] = std::min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
        }
    }
}

/**
 * 区间查询
 * s = floor(log_2(r - l + 1))
 * 将区间分为两部分 [l, l + 2^s - 1] 与 [r - 2^s + 1, r]
 * op两部分结果
 */
int query(int l, int r) {
    int s = std::__lg(r - l + 1);
    return std::max(Max[s][l], Max[s][r - (1 << s) + 1]);
}

int query2(int l, int r) {
    int s = std::__lg(r - l + 1);
    return std::min(Min[s][l], Min[s][r - (1 << s) + 1]);
}

int main() {
    int n = read(), q = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    init(n);

    while (q--) {
        int l = read(), r = read();
        std::cout << query(l, r) - query2(l, r) << std::endl;
    }
}