/**
 * @see https://www.luogu.com.cn/problem/P4551
 * @see https://oi-wiki.org/string/trie/#%E7%BB%B4%E6%8A%A4%E5%BC%82%E6%88%96%E6%9E%81%E5%80%BC
 */
#include <bits/stdc++.h>

const int N = 1e5 + 3;

int head[N], tot;
struct node {
    int to, next, w;
} edge[N << 1];

void add_edge(int u, int v, int w) {
    edge[++tot] = {v, head[u], w};
    head[u] = tot;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
}