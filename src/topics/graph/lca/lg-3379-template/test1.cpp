/**
 * 树链剖分求LCA
 * @see https://blog.csdn.net/qq_41418281/article/details/108220247
 */
#include <bits/stdc++.h>

class HLD {
public:
    HLD(int n) {
        this->n = n;
        matrix.resize(n + 1);
        size.resize(n + 1);
        depth.resize(n + 1);
        top.resize(n + 1);
        son.resize(n + 1);
        parent.resize(n + 1);
    }

    /**
     * 添加双向边
     * @par from 起点
     * @par to 终点
     */
    void add_edge(int from, int to) {
        matrix[from].push_back(to);
        matrix[to].push_back(from);
    }

    /**
     * 遍历cur的邻接结点
     * @par cur 当前节点
     * @par func 对邻接结点执行的逻辑
     * 
     * func
     * @par 邻接结点
     */
    void for_each(int cur, const std::function<void(int)>& func) {
        for(auto& n : matrix[cur]) {
            func(n);
        }
    }

    /**
     * 初始化
     * O(n)
     * @par root 根节点
     */
    void init(int root = 1) {
        dfs1(root);
        dfs2(root, root);
    }

    /**
     * 求解lca
     * O(log n)
     * @par x 节点x
     * @par y 节点y
     * @return 返回节点x和节点y的LCA节点
     */
    int lca(int x, int y) {
        while(top[x] != top[y]) {
            if(depth[top[x]] > depth[top[y]]) {
                x = parent[top[x]];
            } else {
                y = parent[top[y]];
            }
        }
        return depth[x] < depth[y] ? x : y;
    }

    /**
     * 查询两点间的距离
     * @par x 节点x
     * @par y 节点y
     * @return 两点间的距离
     */
    int distance(int x, int y) {
        return depth[x] + depth[y] - (depth[lca(x, y)] << 1);
    }

private:
    int n; // 节点个数
    std::vector<std::vector<int>> matrix; // 邻接矩阵
    std::vector<int> size; // size[i] = j：表示i节点的子树大小为j
    std::vector<int> depth; // depth[i] = j：表示i节点的深度为j
    std::vector<int> top; // top[i] = j：表示i节点所在的重链头部为j
    std::vector<int> son; // son[i] = j：表示i节点的重儿子为j
    std::vector<int> parent; // father[i] = j：表示i节点的父节点为j

    /**
     * 第一次dfs
     * @par cur 当前节点
     */
    void dfs1(int cur) {
        size[cur] = 1;
        depth[cur] = depth[parent[cur]] + 1;
        for_each(cur, [&](int neighbor) {
            if(neighbor == parent[cur]) {
                return; // continue
            }

            parent[neighbor] = cur;
            dfs1(neighbor);
            // 更新当前节点的子树大小
            size[cur] += size[neighbor];
            // 寻找重儿子
            if(size[neighbor] > size[son[cur]]) {
                son[cur] = neighbor;
            }
        });
    }

    /**
     * 第二次dfs
     * @par cur 当前节点
     * @par up 当前节点的重链头部
     */
    void dfs2(int cur, int up) {
        top[cur] = up;
        if(son[cur]) {
            dfs2(son[cur], up);
        }
        for_each(cur, [&](int neighbor) {
            if(neighbor == parent[cur] || neighbor == son[cur]) {
                return; // continue
            }
            dfs2(neighbor, neighbor);
        });
    }
};

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;

    HLD h(n);
    for(int i = 1; i <= n - 1; ++i) {
        int x, y;
        std::cin >> x >> y;
        h.add_edge(x, y);
    }

    h.init(s);

    while(m--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << h.lca(a, b) << std::endl;
    }
}