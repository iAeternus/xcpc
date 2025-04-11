/**
 * C++ 11 版
 */
#include <bits/stdc++.h>

using pii = std::pair<int, int>;
const int N = 1e6 + 5;
const int INF = 1e9;
int n = 2021;
std::vector<std::pair<int, int>> adj[N]; // adj[u] 存储 (目标节点v, 边权w)

void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int dijkstra(int s, int t) {
    std::vector<int> dis(n, INF); // dis[i]: s到i的最短路径
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        auto x = pq.top();
        auto d = x.first;
        auto u = x.second;
        pq.pop();

        if (dis[u] != INF) continue;
        dis[u] = d;
        if (u == t) break;

        for (const auto& it : adj[u]) {
            auto v = it.first;
            auto w = it.second;
            pq.emplace(d + w, v);
        }
    }
    return dis[t];
}

int main() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (abs(i - j) <= 21) {
                auto w = lcm(i, j);
                addEdge(i - 1, j - 1, w);
                addEdge(j - 1, i - 1, w);
            }
        }
    }

    std::cout << dijkstra(0, n - 1) << std::endl;
}