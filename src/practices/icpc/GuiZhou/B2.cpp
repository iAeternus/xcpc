#include <iostream>
#include <set>
#include <vector>
#include <queue>

constexpr int N = 1e5 + 3;
constexpr int INF = 1e9;
std::vector<int> adj[N];

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
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
}