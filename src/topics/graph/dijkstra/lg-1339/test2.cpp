/**
 * Floyd TLE
 */
#include <bits/stdc++.h>

using i64 = long long;
constexpr int INF = 0x3f3f3f3f;

void solve() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    std::vector dis(n, std::vector<int>(n, INF));
    while(m--) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        dis[u][v] = dis[v][u] = w;
    }
    
    auto floyd = [&]() {
        for(int i = 0; i < n; ++i) {
            dis[i][i] = 0;
        }

        for(int k = 0; k < n; ++k) {
            for(int u = 0; u < n; ++u) {
                if(dis[u][k] == INF) continue;
                for(int v = 0; v < n; ++v) {
                    dis[u][v] = std::min(dis[u][v], dis[u][k] + dis[k][v]);
                }
            }
        }
    };

    floyd();

    std::cout << dis[s - 1][t - 1] << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
}