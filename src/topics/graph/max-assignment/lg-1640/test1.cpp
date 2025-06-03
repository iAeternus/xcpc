/**
 * @see https://www.luogu.com.cn/problem/P1640
 * 属性与物品连接建图
 */
#include <bits/stdc++.h>

const int N = 1e6 + 3;

int head[N], tot;

struct node {
    int to, next;
} edge[N << 1];

void addEdge(int u, int v) {
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}

int cur;
int vis[N], match[N];

bool dfs(int x) {
    for (int i = head[x]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (vis[to] != cur) {
            vis[to] = cur;
            if (!match[to] || dfs(match[to])) {
                match[to] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        std::cin >> x >> y;
        addEdge(x, i);
        addEdge(y, i);
    }

    int ans = 0;
    for (int i = 1; i < N; ++i) {
        cur++;
        if (!dfs(i)) {
            ans = i - 1;
            break;
        }
    }
    std::cout << ans << std::endl;
}