#include <bits/stdc++.h>

const int N = 4e6 + 7;
int head[N], tot;

struct Node {
    int to, next, w;
} edge[N << 1];

void addEdge(int u, int v, int w) {
    edge[++tot] = {v, head[u], w};
    head[u] = tot;
}

int main() {
    int n, m, flag;
    scanf("%d %d %d", &n, &m, &flag);
    while(m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        if (!flag) {
            addEdge(v, u, w);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for(int j = head[i]; j; j = edge[j].next) {
            printf("%d %d %d\n", i, edge[j].to, edge[j].w);
        }
    }
}