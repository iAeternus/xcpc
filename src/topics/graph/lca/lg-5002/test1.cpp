/**
 * @see https://www.luogu.com.cn/problem/P5002
 * @see https://www.cnblogs.com/ZAGER/p/9911398.html
 */
#include <bits/stdc++.h>

const int N = 1e4 + 3;

struct Edge {
    int to, next, weight;
} edge[N << 1];

int head[N], cnt;

int size[N]; // size[i] = j：表示i节点的子树大小为j
int ans[N], sum[N];

/**
 * 初始化图
 */
void init() {
    for (auto& h : head) {
        h = -1;
    }
    for (auto& e : edge) {
        e.next = -1;
    }
    cnt = 0;
}

/**
 * 添加边
 * @par from 起点
 * @par to 终点
 * @par weight 边权
 */
void add_edge(int from, int to, int weight = 0) {
    edge[cnt].to = to;
    edge[cnt].weight = weight;
    edge[cnt].next = head[from];
    head[from] = cnt++;
}

/**
 * 遍历cur的邻接结点
 * @par cur 当前节点
 * @par func 对邻接结点的操作逻辑
 */
void for_each(int cur, const std::function<void(int)>& func) {
    for (int i = head[cur]; ~i; i = edge[i].next) {
        func(i);
    }
}

void dfs(int cur, int parent) {
    size[cur] = 1;
    for_each(cur, [&](int i) {
        int neighbor = edge[i].to;
        if (neighbor == parent) {
            return; // continue
        }
        dfs(neighbor, cur);

        size[cur] += size[neighbor];
        sum[cur] += size[neighbor] * size[neighbor];
    });
    ans[cur] = size[cur] * size[cur] - sum[cur];
}

int main() {
    init();
    int n, r, m;
    std::cin >> n >> r >> m;

    for (int i = 1, a, b; i <= n - 1; ++i) {
        std::cin >> a >> b;
        add_edge(a, b);
        add_edge(b, a);
    }

    dfs(r, -1);

    while (m--) {
        int p;
        std::cin >> p;
        std::cout << ans[p] << std::endl;
    }
}