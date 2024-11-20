/**
 * @see https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
 * 下标从 1 开始
 */
#include <bits/stdc++.h>

const int N = 3e5 + 7;

struct Info {
    int max, min, cnt;
} info[N];

int fa[N];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        info[i] = {i, i, 1};
    }
}

int query(int x) {
    while (x != fa[x]) {
        x = fa[x] = fa[fa[x]];
    }
    return x;
}

bool merge(int x, int y) {
    int fx = query(x);
    int fy = query(y);
    if (fx == fy) {
        return false;
    }
    fa[fy] = fx;
    info[fx].max = std::max(info[fx].max, info[fy].max);
    info[fx].min = std::min(info[fx].min, info[fy].min);
    info[fx].cnt += info[fy].cnt;
    return true;
}

bool same(int x, int y) {
    return query(x) == query(y);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    init(n);
    while (m--) {
        std::string op;
        int u, v;
        std::cin >> op;
        if (op == "get") {
            std::cin >> v;
            int fv = query(v);
            std::cout << info[fv].min << ' ' << info[fv].max << ' ' << info[fv].cnt << std::endl;
        } else {
            std::cin >> u >> v;
            merge(u, v);
        }
    }
}