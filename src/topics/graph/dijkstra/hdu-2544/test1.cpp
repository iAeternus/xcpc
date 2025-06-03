/**
 * @see https://acm.hdu.edu.cn/showproblem.php?pid=2544
 * Floyd-Warshall
 */
#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) {
            return 0;
        }

        std::vector g(n, std::vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            g[i][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            u--, v--;
            g[u][v] = g[v][u] = w;
        }

        for (int k = 0; k < n; ++k) {
            for (int u = 0; u < n; ++u) {
                if (g[u][k] == INF) continue;
                for (int v = 0; v < n; ++v) {
                    g[u][v] = std::min(g[u][v], g[u][k] + g[k][v]);
                }
            }
        }
        std::cout << g[0][n - 1] << std::endl;
    }
}