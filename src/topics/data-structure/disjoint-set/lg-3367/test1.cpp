/**
 * @see https://www.luogu.com.cn/problem/P3367
 */
#include <bits/stdc++.h>

const int N = 2e5 + 3;
int n, m;
int fa[N], rk[N];

void init(int sz) {
    std::fill(rk, rk + sz, 0);
    for(int i = 0; i < sz; ++i) {
        fa[i] = i;
    }
}

/**
 * @brief 查询x的组长 
 */
int query(int x) {
    while(x != fa[x]) {
        x = fa[x] = fa[fa[x]];
    }
    return x;
}

/**
 * @brief 合并x和y为一组
 * @return true=合并成功 false=合并失败，x和y已在同一组内
 */
bool merge(int x, int y) {
    auto fx = query(x), fy = query(y);
    if(fx == fy) return false;

    if(rk[fx] > rk[fy]) {
        fa[fy] = fx;
    } else {
        fa[fx] = fy;
        if(rk[fx] == rk[fy]) {
            ++rk[fy];
        }
    }

    return true;
}

/**
 * @brief 查询x和y是否在一组
 */
bool is_same(int x, int y) {
    return query(x) == query(y);
}

int main() {
    std::cin >> n >> m;
    init(n);
    while(m--) {
        int z, x, y;
        std::cin >> z >> x >> y;
        if(z == 1) {
            merge(x, y);
        } else {
            std::cout << (is_same(x, y) ? 'Y' : 'N') << '\n';
        }
    }
}