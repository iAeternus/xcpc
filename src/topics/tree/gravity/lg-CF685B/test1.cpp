/**
 * @see https://codeforces.com/problemset/problem/685/B
 * @see https://www.luogu.com.cn/problem/CF685B
 * 树的重心：删除重心后，使得形成的所有子树的结点数最大值最小
 * 在 DFS 中计算每个子树的大小，记录「向下」的子树的最大大小，
 * 利用总点数 - 当前子树（这里的子树指有根树的子树）的大小得到「向上」的子树的大小，
 * 然后就可以依据定义找到重心了
 */
#include <bits/stdc++.h>

const int N = 3e5 + 5;
int n, q;
int fa[N];
std::vector<int> son[N];
int siz[N]; // 子树大小
int ans[N]; // 以节点 u 为根的子树重心是 ans[u]
int wei[N]; // 节点重量

// 求出所有子树的重心
void dfs(int u) {
    siz[u] = 1;
    ans[u] = u;
    for (int v : son[u]) {
        dfs(v);
        siz[u] += siz[v];
        wei[u] = std::max(wei[u], siz[v]);
    }
    for (int v : son[u]) {
        int p = ans[v];
        while (p != u) {
            if (std::max(wei[p], siz[u] - siz[p]) <= siz[u] / 2) {
                ans[u] = p;
                break;
            } else {
                p = fa[p];
            }
        }
    }
}

int main() {
    std::cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        std::cin >> fa[i];
        son[fa[i]].push_back(i);
    }
    dfs(1);
    while (q--) {
        int u;
        std::cin >> u;
        std::cout << ans[u] << std::endl;
    }
}