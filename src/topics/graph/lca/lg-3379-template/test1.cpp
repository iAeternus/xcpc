/**
 * 树链剖分求LCA
 * @see https://blog.csdn.net/qq_41418281/article/details/108220247
 */
#include <bits/stdc++.h>

struct HLD {
    int n;                                 // 节点个数
    std::vector<std::vector<int>> matrix;  // 邻接矩阵
    std::vector<int> siz;                  // siz[u]: 存以u为根的子树的结点数
    std::vector<int> dep;                  // dep[u]: 存u的深度
    std::vector<int> top;                  // top[u]: 存u所在重链的顶点
    std::vector<int> son;                  // son[u]: 存u的重儿子
    std::vector<int> fa;                   // fa[u]: 存u的父节点

    HLD(int n) {
        this->n = n;
        matrix.resize(n + 1);
        siz.resize(n + 1);
        dep.resize(n + 1);
        top.resize(n + 1);
        son.resize(n + 1);
        fa.resize(n + 1);
    }

    /**
     * 添加双向边
     */
    void addEdge(int u, int v) {
        matrix[u].push_back(v);
        matrix[v].push_back(u);
    }

    /**
     * 遍历u的邻接结点
     */
    void forEach(int u, const std::function<void(int)>& func) {
        for (auto& n : matrix[u]) {
            func(n);
        }
    }

    /**
     * 初始化
     * O(n)
     */
    void init(int root = 1) {
        dfs1(root, 0);
        dfs2(root, root);
    }

    /**
     * 求解lca
     * O(log n)
     */
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) {
                std::swap(u, v);
            }
            u = fa[top[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }

    /**
     * 查询两点间的距离
     */
    int distance(int u, int v) {
        return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
    }

    /**
     * 第一次dfs
     */
    void dfs1(int u, int father) {
        fa[u] = father;
        dep[u] = dep[fa[u]] + 1;
        siz[u] = 1;
        forEach(u, [&](int neighbor) {
            if (neighbor == fa[u]) {
                return;  // continue
            }

            dfs1(neighbor, u);
            // 更新当前节点的子树大小
            siz[u] += siz[neighbor];
            // 寻找重儿子
            if (siz[neighbor] > siz[son[u]]) {
                son[u] = neighbor;
            }
        });
    }

    /**
     * 第二次dfs
     */
    void dfs2(int u, int t) {
        top[u] = t;
        if (!son[u]) {
            return;
        }
        dfs2(son[u], t);
        forEach(u, [&](int neighbor) {
            if (neighbor == fa[u] || neighbor == son[u]) {
                return;  // continue
            }
            dfs2(neighbor, neighbor);
        });
    }
};

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;

    HLD h(n);
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        h.addEdge(u, v);
    }

    h.init(s);

    while (m--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << h.lca(a, b) << std::endl;
    }
}