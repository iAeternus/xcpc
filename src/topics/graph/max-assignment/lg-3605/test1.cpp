/**
 * @see https://www.luogu.com.cn/problem/B3605
 */
#include <bits/stdc++.h>

const int N = 2.5e5 + 3;

int head[N], tot;

struct node {
    int to, next;
} edge[N << 1];

void addEdge(int u, int v) {
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}

bool vis[N];
int match[N];

bool dfs(int x) {
    for(int i = head[x]; i; i = edge[i].next) {
        int to = edge[i].to;
        if(!vis[to]) {
            vis[to] = true;
            if(!match[to] || dfs(match[to])) {
                match[to] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nl, nr, m;
    std::cin >> nl >> nr >> m;
    while(m--) {
        int u, v;
        std::cin >> u >> v;
        addEdge(u, v);
    }

    int ans = 0;
    for(int i = 1; i <= nl; ++i) {
        ans += dfs(i);
        memset(vis, 0, sizeof(vis));
    }
    std::cout << ans << std::endl;
}