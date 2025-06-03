/**
 * @see https://www.luogu.com.cn/problem/P1339
 */
#include <bits/stdc++.h>

using i64 = long long;
constexpr int INF = 1e9;

void solve() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    std::vector<std::vector<std::pair<int, i64>>> adj(n);
    while (m--) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;
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

    std::cout << dijkstra(s - 1, t - 1) << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
}