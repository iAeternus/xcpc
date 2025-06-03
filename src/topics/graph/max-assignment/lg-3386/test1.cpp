/**
 * @see https://www.luogu.com.cn/problem/P3386
 */
#include <bits/stdc++.h>

const int N = 1e3 + 5;
int n, m, e, ans;
bool a[N][N], vis[N];
int match[N];

bool dfs(int x) {
    for (int i = 1; i <= m; ++i) {
        if (!vis[i] && a[x][i]) {
            vis[i] = true;
            if (!match[i] || dfs(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::cin >> n >> m >> e;
    while (e--) {
        int u, v;
        std::cin >> u >> v;
        a[u][v] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        ans += dfs(i);
        std::fill(vis + 1, vis + n + 1, false);
    }

    std::cout << ans << std::endl;
}