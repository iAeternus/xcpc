#include <bits/stdc++.h>

const int N = 1e6 + 5;
int head[N], tot;

struct node {
    int to, next;
} edge[N << 1];

void addEdge(int u, int v) {
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}

int main() {
}