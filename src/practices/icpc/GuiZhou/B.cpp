#include <iostream>
#include <set>
#include <vector>
#include <queue>

constexpr int INF = 1e9;

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<std::pair<int, int>>> adj(n, {INF, INF});
    std::vector<int> p(k);
    for(int i = 0; i < k; ++i) {
        std::cin >> p[k];
    }

    int s, t;
    std::cin >> s >> t;

    while (m--) {
        int u, v, w;
        std::cin >> u >> v >> w;
        if(adj[u][v] != std::make_pair(INF, INF)) {
            adj[u][v] = std::min(adj[u][v], w);
            continue;
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    std::set<int> weights;
    auto dijkstra = [&](int s, int t) {
        std::vector<int> dis(n, INF);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.emplace(0, s);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (dis[u] != INF) {
                continue;
            }
            dis[u] = d;

            for (const auto& [v, w] : adj[u]) {
                pq.emplace(d + w, v);
            }
        }
        return dis[t];
    };

    // TODO
}