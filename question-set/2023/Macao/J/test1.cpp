/**
 * @see https://codeforces.com/gym/104891/problem/J
 * 
 * Wrong answer on test 6
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

int dijkstra(int s, int t) {
    std::priority_queue<std::pair<int, int>> pq;
    
    for(int i = 0; i <= n; ++i) {
        dist[i] = INT_MAX;
        vis[i] = 0;
    }

    dist[s] = 0, pq.push(std::make_pair(0, s));
    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if(vis[cur]) {
            continue;
        }
        vis[cur] = 1;
        for(int i = head[cur]; ~i; i = e[i].next) {
            int y = e[i].to;
            if(dist[y] > dist[cur] + 1) {
                dist[y] = dist[cur] + 1;
                pq.push(std::make_pair(dist[y], y));
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

    for(int i = 0; i <= n; ++i) {
        head[i] = -1;
        int v = (i + a[i % n]) % n;
        if(v == 0) {
            v = n;
        }
        addEdge(i, v);
        if(i) {
            v = i + 1;
            if(v > n) {
                v = 1;
            }
            addEdge(i, v);
        }
    }
    std::cout << dijkstra(0, x) << std::endl;
}