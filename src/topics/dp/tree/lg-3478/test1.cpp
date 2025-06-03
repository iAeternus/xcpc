/**
 * @see https://www.luogu.com.cn/problem/P3478
 */
#include <bits/stdc++.h>

const int N = 1e6 + 3;
int n;

struct node {
    int to, next;
} edge[N << 1];

int head[N], tot;

void addEdge(int u, int v) {
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}

int dep[N]; // dep[u]: u的深度
int siz[N]; // siz[u]: 以u为根的子树的节点数
int sum[N]; // sum[u]: 以u为根时所有节点深度之和

// 搞出dep siz
void dfs1(int u, int fa) {
    dep[u] = dep[fa] + 1;
    sum[1] += dep[u]; // init
    siz[u] = 1;
    for (int i = head[u]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == fa) continue;
        dfs1(to, u);
        siz[u] += siz[to];
    }
}

// 换根dp
/*
(1)所有在v的子树上的结点深度都减少 1，总深度和减少 siz[v]
(2)所有不在v的子树上的结点深度都增加 1，总深度和增加 n-siz[v],
状态转移 sum[v] = sum[u] - siz[v] + n - siz[v]
*/
void dfs2(int u, int fa) {
    for (int i = head[u]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == fa) continue;
        sum[to] = sum[u] - siz[to] + n - siz[to];
        dfs2(to, u);
    }
}

int main() {
    std::cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int s = sum[1], ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (s < sum[i]) {
            s = sum[i];
            ans = i;
        }
    }
    std::cout << ans << std::endl;
}