/**
 * @see https://www.luogu.com.cn/problem/P2607
 * 全WA了，但是不知道哪里WA了 T_T
 */
#include <bits/stdc++.h>

using i64 = long long;
const int N = 1e6 + 3;

int head[N], tot;
struct Node {
    int to, next;
} edges[N << 1];

bool vis[N];
i64 dp[N][2], w[N], sum, r1, r2;

void addEdge(int u, int v) {
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}

// 找环
bool find(int u, int rt) {
    vis[u] = true;
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == rt) {
            r1 = u;
            return true;
        }
        if (!vis[v] && find(v, rt)) return true;
    }
    return false;
}

// 树上dp
i64 dfs(int u, int rt) {
    dp[u][0] = 0;
    dp[u][1] = w[u];
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == rt) continue;
        dfs(v, rt);
        dp[u][0] += std::max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    return dp[u][0];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    for (int u = 1, v; u <= n; ++u) {
        std::cin >> w[u] >> v;
        addEdge(u, v);
    }

    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        r2 = i;
        if (find(i, i)) { // 从自己走到自己，说明有环
            sum += std::max(dfs(r1, r1), dfs(r2, r2));
        }
    }
    std::cout << sum << std::endl;
}