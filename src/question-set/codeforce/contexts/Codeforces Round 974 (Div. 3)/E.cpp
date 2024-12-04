/**
 * @see https://codeforces.com/contest/2014/problem/E
 * 领接矩阵
 */
#include <bits/stdc++.h>

using i64 = long long;
using tllb = std::tuple<i64, i64, bool>;
constexpr i64 INF = 1e18;

void solve() {
    int n, m, h;
    std::cin >> n >> m >> h;
    std::vector<bool> has_horse(n, false);
    for(int i = 0; i < h; ++i) {
        int a;
        std::cin >> a;
        a--;
        has_horse[a] = true;
    }
    std::vector<std::vector<std::pair<int, int>>> g(n);
    while(m--) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    /*
    tllb -> (d, u, horse)
    d-从源点s到当前点的最短路径距离
    u-当前节点编号
    horse-当前节点是否有马

    dis[i][0]: 走路时路径的最短距离
    dis[i][1]: 骑马时路径的最短距离

    vis[i][0]: 当前节点是走路访问的
    vis[i][1]: 当前节点是骑马访问的
    */
    auto dijkstra = [&](int s) {
        std::priority_queue<tllb, std::vector<tllb>, std::greater<tllb>> pq;
        pq.push({0LL, s, false});
        std::vector<std::array<i64, 2>> dis(n, {INF, INF});
        dis[s][0] = 0LL;
        std::vector<std::array<bool, 2>> vis(n);
        while(!pq.empty()) {
            auto[d, u, horse] = pq.top();
            pq.pop();
            
            if(vis[u][horse]) continue;
            vis[u][horse] = true;

            if(!horse && has_horse[u]) {
                pq.push({d, u, true});
            }

            for(const auto&[v, w] : g[u]) {
                i64 nw = horse ? w / 2 : w;
                if(dis[v][horse] > d + nw) {
                    dis[v][horse] = d + nw;
                    pq.push({dis[v][horse], v, horse});
                }
            }
        }

        std::vector<i64> d(n);
        for(int i = 0; i < n; ++i) {
            d[i] = std::min(dis[i][0], dis[i][1]);
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