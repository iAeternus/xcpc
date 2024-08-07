/**
 * https://www.luogu.com.cn/problem/P1462
 */
#include <bits/stdc++.h>

using ll = long long;
using WEIGHT = int;  // 边权类型
using POINT = int;   // 点权类型

#define INF 0x7fffffff  // 最大权值

const int N = 1e5 + 5;  // 最大点数
const int M = N << 1;   // 最大边数

POINT head[N];  // 点集
int cnt;        // cnt记录当前存储位置
bool vis[N];

ll n, m, s, hp, f[N], u[N];

struct Edge {
    int from;  // 边的起点
    int to;    // 边的终点
    int next;  // 起点的下一个邻居
    WEIGHT w;  // 边权
} edge[M];     // 边集

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

static void init_vis() {
    memset(vis, 0, sizeof vis);
}

bool SPFA(int s, int top) {
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
            if (dist[to] > dist[cur] + w && f[to] <= top) {
                dist[to] = dist[cur] + w;
                if (!vis[to]) {
                    q.push(to);
                    vis[to] = true;
                }
            }
        });
    }
   
    return dist[n] < hp;
}

int bin_search(int left, int right) {
    int ans = 0;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(SPFA(1, u[mid])) {
            ans = u[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    // freopen("P1462_1.in", "r", stdin);

    init();
    scanf("%d %d %d", &n, &m, &hp);

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]);
        u[i] = f[i];
    }

    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    if(!SPFA(1, INF)) {
        puts("AFK");
        return 0;
    }

    std::sort(u + 1, u + n + 1);
    printf("%d\n", bin_search(1, n));
}