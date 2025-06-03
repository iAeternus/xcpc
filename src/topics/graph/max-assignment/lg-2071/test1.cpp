/**
 * @see https://www.luogu.com.cn/problem/P2071
 */
#include <bits/stdc++.h>

const int N = 4e3 + 3;

int head[N], tot;

struct node {
    int to, next;
} edge[N << 1];

void addEdge(int u, int v) {
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}

bool vis[N];
int match[N][2]; // i-哪一排 j-哪个座位

bool dfs(int x) {
    for (int i = head[x]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (!vis[to]) {
            vis[to] = true;
            for (int j = 0; j < 2; ++j) { // 每排两个座位
                if (!match[to][j] || dfs(match[to][j])) {
                    match[to][j] = x;
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;
    int n2 = n << 1;
    for (int i = 1; i <= n2; ++i) {
        int u, v;
        std::cin >> u >> v;
        addEdge(i, u);
        addEdge(i, v);
    }

    int ans = 0;
    for (int i = 1; i <= n2; ++i) {
        ans += dfs(i);
        memset(vis, 0, sizeof(vis));
    }
    std::cout << ans << std::endl;
}