/**
 * 
 */
#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) {
            return 0;
        }
        std::vector<std::vector<std::pair<int, int>>> adj(n);

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            u--, v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        auto dijkstra = [&](int s, int t) {
            std::vector<int> dis(n, INF);
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
            pq.emplace(0, s);

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (dis[u] != INF) continue;
                dis[u] = d;
                if (u == t) break;

                for (const auto& [v, w] : adj[u]) {
                    pq.emplace(d + w, v);
                }
            }
            return dis[t];
        };

        std::cout << dijkstra(0, n - 1) << std::endl;
    }
}