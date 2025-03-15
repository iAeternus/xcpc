/**
 * @see https://codeforces.com/gym/104891/problem/J
 */
#include <bits/stdc++.h>

const int N = 1e5 + 10;
int n, x;
int a[N];

struct edge {
    int to, next;
} e[N << 2];

int num, head[N];

void addEdge(int u, int v) {
    e[++num] = (edge){v, head[u]};
    head[u] = num;
}

int dist[N], vis[N];

struct node {
    int pos, d;
    bool operator<(const node& x) const {
        return x.d < d;
    }
};

std::priority_queue<node> pq;

int dijkstra(int s, int t) {
    for (int i = 0; i <= n; ++i) {
        dist[i] = INT_MAX;
        vis[i] = 0;
    }

    dist[s] = 0, pq.push({s, 0});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (vis[cur.pos]) {
            continue;
        }
        vis[cur.pos] = 1;
        for (int i = head[cur.pos]; ~i; i = e[i].next) {
            int y = e[i].to;
            if (dist[y] > dist[cur.pos] + 1) {
                dist[y] = dist[cur.pos] + 1;
                pq.push({y, dist[y]});
            }
        }
    }
    return dist[t];
}

int main() {
    std::cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i <= n; ++i) {
        head[i] = -1;
        int v = (i + a[i % n]) % n;
        if (v == 0) {
            v = n;
        }
        addEdge(i, v);
        if (i) {
            v = i + 1;
            if (v > n) {
                v = 1;
            }
            addEdge(i, v);
        }
    }
    std::cout << dijkstra(0, x) << std::endl;
}