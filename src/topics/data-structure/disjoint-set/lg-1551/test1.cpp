/**
 * @see https://www.luogu.com.cn/problem/P1551
 */
#include <bits/stdc++.h>

const int N = 5e4 + 3;
int fa[N];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int query(int x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = query(fa[x]);
}

void merge(int x, int y) {
    fa[query(y)] = query(x);
}

bool same(int x, int y) {
    return query(x) == query(y);
}

int main() {
    int n, m, p;
    std::cin >> n >> m >> p;
    init(n);
    while (m--) {
        int mi, mj;
        std::cin >> mi >> mj;
        merge(mi, mj);
    }
    while (p--) {
        int pi, pj;
        std::cin >> pi >> pj;
        std::cout << (same(pi, pj) ? "Yes" : "No") << std::endl;
    }
}