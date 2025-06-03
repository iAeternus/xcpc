/**
 * @see https://www.luogu.com.cn/problem/P2420
 * 
 * 只需要分别求出从根节点到两个子节点的路径异或和，
 * 再将两者异或即可消掉公共的路径部分，
 * 留下两子节点的路径异或和
 */
#include <bits/stdc++.h>

const int N = 1e5 + 3;

struct Edge {
    int to, next, weight;
} edge[N << 1];

int head[N], cnt;

int xor_path[N]; // xor_path[i] = j：表示节点i到根节点的路径异或和为j

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
void add_edge(int from, int to, int weight) {
    edge[cnt].to = to;
    edge[cnt].weight = weight;
    edge[cnt].next = head[from];
    head[from] = cnt++;
}

/**
 * 遍历cur的邻接结点
 * @par cur 当前节点
 * @par func 对邻接结点的操作逻辑，参数为邻接节点的索引
 * @brief 可以使用以下代码遍历邻接节点
 *      for_each(cur, [&](int i) {
 *          int neighbor = edge[i].to;
 *          int weight = edge[i].weight;
 *          ...
 *      })
 */
void for_each(int cur, const std::function<void(int)>& func) {
    for (int i = head[cur]; ~i; i = edge[i].next) {
        func(i);
    }
}

/**
 * 深搜求路径和
 * @par cur 当前节点
 * @par parent 当前节点的父节点
 */
void dfs(int cur, int parent) {
    for_each(cur, [&](int i) {
        int neighbor = edge[i].to;
        int weight = edge[i].weight;
        if (neighbor == parent) {
            return; // continue
        }
        xor_path[neighbor] = xor_path[cur] ^ weight;
        dfs(neighbor, cur);
    });
}

int main() {
    int n;
    std::cin >> n;
    init();
    for (int i = 1; i <= n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    dfs(1, -1);

    int m;
    std::cin >> m;
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << (xor_path[u] ^ xor_path[v]) << std::endl;
    }
}