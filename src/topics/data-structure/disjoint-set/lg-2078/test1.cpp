/**
 * @see https://www.luogu.com.cn/problem/P2078
 */
#include <bits/stdc++.h>

const int N = 2e4 + 3;
int fa[N];

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int query(int x) {
    if(x == fa[x]) {
        return x;
    }
    return fa[x] = query(fa[x]);
}

void merge(int x, int y) {
    int r1 = query(x);
    int r2 = query(y);
    if(r1 != r2) {
        fa[r2] = r1;
    }
}

bool same(int x, int y) {
    return query(x) == query(y);
}

int main() {
    int n, m, p, q;
    std::cin >> n >> m >> p >> q;
    init(n + m);
    while(p--) {
        int x, y;
        std::cin >> x >> y;
        merge(x, y);
    }
    while(q--) {
        int x, y;
        std::cin >> x >> y;
        x *= -1;
        y *= -1;
        merge(x + n, y + n);
    }

    merge(1, 1 + n);

    int cntMale = 0, cntFemale = 0;
    for(int i = 1; i <= n; ++i) {
        if(same(1, i)) {
            ++cntMale; // 计算男生人数
        }
    }
    for(int i = n + 1; i <= n + m; ++i) {
        if(same(n + 1, i)) {
            ++cntFemale; // 计算女生人数
        }
    }
    std::cout << std::min(cntMale, cntFemale) << std::endl;
}