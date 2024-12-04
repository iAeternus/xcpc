/**
 * @see https://codeforces.com/contest/2014/problem/E
 * 一个更精巧的实现
 */
#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 INF = 1e18;

void solve() {
    int n, m, h;
    std::cin >> n >> m >> h;
    std::vector<bool> horse(n, false);
    for(int i = 0; i < h; ++i) {
        int a;
        std::cin >> a;
        a--;
        horse[a] = true;
    }
    std::vector<std::vector<std::pair<int, i64>>> adj(n);
    while(m--) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto dijkstra = [&](int s) {
       std::vector<i64> dis(2 * n, INF); // dis[2i]-骑马最短距离，dis[2i + 1]-不骑马最短距离
       std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> pq;
       pq.emplace(0LL, 2 * s);

       while(!pq.empty()) {
            auto[d, u] = pq.top(); // d-最短路径 u-虚拟的节点
            pq.pop();

            if(dis[u] != INF) {
                continue;
            }
            dis[u] = d;

            int x = u / 2; // 当前节点
            bool has_horse = u & 1;

            if(!has_horse && horse[x]) {
                pq.emplace(d, 2 * x + 1);
            }

            for(const auto&[v, w] : adj[x]) {
                pq.emplace(d + (has_horse ? w / 2 : w), 2 * v + has_horse);
            }
       }
       std::vector<i64> d(n, INF); // 骑马和不骑马的较小值
       for (int i = 0; i < n; ++i) {
           d[i] = std::min(dis[2 * i], dis[2 * i + 1]);
       }
       return d;
    };

    auto d1 = dijkstra(0);
    auto dn = dijkstra(n - 1);

    i64 ans = INF;
    for(int i = 0; i < n; ++i) {
        ans = std::min(ans, std::max(d1[i], dn[i]));
    }
    std::cout << (ans == INF ? -1 : ans) << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}