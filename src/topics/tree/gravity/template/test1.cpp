/**
 * 求有根树的重心
 * 下标从1开始
 */
#include <bits/stdc++.h>

const int N = 1e5 + 3;

struct node {
    int to, next;
} edge[N << 1];

int head[N], tot;

void addEdge(int u, int v) {
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}

int n;
int siz[N]; // 这个节点的「大小」（所有子树上节点数 + 该节点）
int wei[N]; // 这个节点的「重量」，即所有子树「大小」的最大值
int ans[2]; // 用于记录树的重心（存的是节点编号）

// 求有根树的重心
void dfs(int cur, int fa) {
    siz[cur] = 1;
    wei[cur] = 0;
    for(int i = head[cur]; i; i = edge[i].next) {
        int to = edge[i].to;
        if(to != fa) { // 只准往下走
            dfs(to, cur);
            siz[cur] += siz[to];
            wei[cur] = std::max(wei[cur], siz[to]);
        }
    }
    wei[cur] = std::max(wei[cur], n - siz[cur]);
    if(wei[cur] <= n / 2) { // 依照树的重心的定义统计
        ans[ans[0] != 0] = cur;
    }
}

void clear() {
    memset(edge, 0, sizeof edge);
    memset(head, 0, sizeof head);
    tot = 0;
    memset(siz, 0, sizeof siz);
    memset(wei, 0, sizeof wei);
    memset(ans, 0, sizeof ans);
}

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        clear();
        std::cin >> n;
        int n2 = n << 1;
        for(int i = 1; i <= n2; ++i) {
            int u, v;
            std::cin >> u >> v;
            addEdge(u, v);
            addEdge(v, u);
        }
        dfs(1, 0);
        std::cout << ans[0] << ' ' << ans[1] << std::endl;
    }
}