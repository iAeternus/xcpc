/**
 * @see https://www.luogu.com.cn/problem/P3379
 * 树链剖分 O(n + m log n)
 * buggy code with WA!!
 */
#include <bits/stdc++.h>

const int N = 5e5 + 3;
int head[N], tot;
struct node {
    int to, next;
} edge[N << 1];

void addEdge(int u, int v) {
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}

/*
fa[u]: 存u的父节点
dep[u]: 存u的深度
son[u]: 存u的重儿子
siz[u]: 存以u为根的子树的结点数
*/
int fa[N], dep[N], son[N], siz[N];
// top[u]: 存u所在重链的顶点
int top[N];

// 第一遍dfs，搞出 fa dep son siz
void dfs1(int u, int father) {
    fa[u] = father;
    dep[u] = dep[father] + 1;
    siz[u] = 1;
    for (int i = head[u]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == father) { // 只准往下走
            continue;
        }
        // fa[to] = u;
        dfs1(to, u);
        siz[u] += siz[to];
        if (siz[son[u]] < siz[to]) {
            son[u] = to;
        }
    }
}

// 第二遍dfs，搞出 top
void dfs2(int u, int t) {
    top[u] = t;
    if (!son[u]) {
        return;
    }
    dfs2(son[u], t); // 搜重儿子
    for (int i = head[u]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == fa[u] || to == son[u]) { // 只准往下走 && 不能选刚才走的重儿子
            continue;
        }
        dfs2(to, to); // 搜轻儿子
    }
}

// 维护两个游标，当两个游标在一条重链上时，深度小的就是lca
int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) {
            std::swap(u, v);
        }
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

// 两节点的距离
int dis(int u, int v) {
    return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << lca(a, b) << std::endl;
    }
}
