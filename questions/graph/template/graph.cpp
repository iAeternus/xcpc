#include <cstring>
#include <queue>

#include "graph.h"

POINT head[N];
Edge edge[M];
int cnt = 0;

void init() {
    // 点初始化
    for (POINT& h : head) {
        h = -1;
    }
    // 边初始化
    for (auto& e : edge) {
        e.next = -1;
    }
    cnt = 0;
}

void add_edge(int u, int v, WEIGHT w) {
    edge[cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void for_each(int u, const std::function<void(int)>& func) {
    // ~i 等价于 i != -1
    for (int i = head[u]; ~i; i = edge[i].next) {
        func(i);
    }
}

bool vis[N];

static void init_vis() {
    memset(vis, 0, sizeof vis);
}

static void dfs_algorithm(int u, const std::function<void(int)>& func) {
    func(u);
    vis[u] = true;
    for_each(u, [&](int i) {
        int to = edge[i].to;
        if (!vis[to]) {
            dfs_algorithm(to, func);
        }
    });
}

void dfs(int u, const std::function<void(int)>& func) {
    init_vis();
    dfs_algorithm(u, func);
}

void bfs(int u, const std::function<void(int)>& func) {
    init_vis();
    std::queue<int> q;
    vis[u] = true;
    q.push(u);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        func(k);
        for_each(k, [&](int i) {
            int to = edge[i].to;
            if (!vis[to]) {
                q.push(to);
                vis[to] = true;
            }
        });
    }
}

WEIGHT dijkstra(int s, int t) {
    WEIGHT dist[N];
    // first-索引 second-权值
    std::priority_queue<std::pair<int, WEIGHT>> pq;

    init_vis();
    std::fill(dist, dist + N, INF);

    dist[s] = 0;
    pq.push(std::make_pair(s, 0));

    while (!pq.empty()) {
        int cur = pq.top().first;
        pq.pop();
        if (vis[cur]) {
            continue;
        }
        vis[cur] = true;

        for_each(cur, [&](int i) {
            int to = edge[i].to;
            WEIGHT w = edge[i].w;
            if (dist[to] > dist[cur] + w) {
                dist[to] = dist[cur] + w;
                pq.push(std::make_pair(to, -dist[to]));
            }
        });
    }
    return dist[t];
}

WEIGHT SPFA(int s, int t) {
    WEIGHT dist[N];
    std::queue<int> q;

    init_vis();
    std::fill(dist, dist + N, INF);

    q.push(s);
    vis[s] = true;
    dist[s] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        vis[cur] = false;

        for_each(cur, [&](int i) {
            int to = edge[i].to;
            WEIGHT w = edge[i].w;
            if (dist[to] > dist[cur] + w) {
                dist[to] = dist[cur] + w;
                if (!vis[to]) {
                    q.push(to);
                    vis[to] = true;
                }
            }
        });
    }
    return dist[t];
}

WEIGHT SPFA_SLF(int s, int t) {
    WEIGHT dist[N];
    std::deque<int> dq;

    init_vis();
    std::fill(dist, dist + N, INF);

    dq.push_back(s);
    vis[s] = true;
    dist[s] = 0;

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        vis[cur] = false;

        for_each(cur, [&](int i) {
            int to = edge[i].to;
            WEIGHT w = edge[i].w;
            if (dist[to] > dist[cur] + w) {
                dist[to] = dist[cur] + w;
                if (!vis[to]) {
                    vis[to] = true;
                    if (dq.size() && dist[to] >= dist[dq.front()]) {
                        dq.push_back(to);
                    } else {
                        dq.push_front(to);
                    }
                }
            }
        });
    }

    return dist[t];
}

WEIGHT SPFA_LLL(int s, int t) {
    WEIGHT dist[N];
    std::deque<int> dq;
    int num = 0;
    ll x = 0;

    init_vis();
    std::fill(dist, dist + N, INF);

    dq.push_back(s);
    vis[s] = true;
    dist[s] = 0;
    ++num;

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        --num;
        x -= dist[cur];

        while (num && dist[cur] > x / num) {
            dq.push_back(cur);
            cur = dq.front();
            dq.pop_front();
        }

        vis[cur] = false;

        for_each(cur, [&](int i) {
            int to = edge[i].to;
            WEIGHT w = edge[i].w;
            if (dist[to] > dist[to] + w) {
                dist[to] = dist[to] + w;
                if (!vis[to]) {
                    vis[to] = true;
                    ++num;
                    x += dist[to];
                    if (dq.size() && dist[to] >= dist[dq.front()]) {
                        dq.push_back(to);
                    } else {
                        dq.push_front(to);
                    }
                }
            }
        });
    }
    return dist[t];
}