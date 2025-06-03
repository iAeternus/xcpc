#include <bits/stdc++.h>

// 树链剖分
template <typename T>
struct HLD {
    // 线段树节点
    struct Node {
        int l, r;
        T val, sum;
    };

    // 树链剖分相关数据
    int n;                              // 节点个数
    std::vector<T> w;                   // 节点权值
    std::vector<std::vector<int>> edge; // 树边
    std::vector<int> fa;                // fa[u]: 存u的父节点
    std::vector<int> dep;               // dep[u]: 存u的深度
    std::vector<int> son;               // son[u]: 存u的重儿子
    std::vector<int> siz;               // siz[u]: 存以u为根的子树的结点数
    std::vector<int> top;               // top[u]: 存u所在重链的顶点

    // 树上修改相关数据
    int cnt;                // 新编号计数
    std::vector<int> id;    // id[u]: 存u剖分后的新编号
    std::vector<T> nw;      // 存新编号在树中所对应节点的权值
    std::vector<Node> tree; // 线段树

    HLD(int n, const std::vector<T>& w) {
        this->n = n;
        this->w = w;
        edge.resize(n + 1);
        fa.resize(n + 1);
        dep.resize(n + 1);
        son.resize(n + 1);
        siz.resize(n + 1);
        top.resize(n + 1);

        this->cnt = 0;
        id.resize(n + 1);
        nw.resize(n + 1);
        tree.resize(n << 2); // 4n
    }

    /**
     * 添加边
     */
    void addEdge(int u, int v) {
        edge[u].push_back(v);
    }

    /**
     * 初始化
     * O(n)
     */
    void init(int root = 1) {
        dfs1(root, 0);
        dfs2(root, root);
        build(1, 1, n);
    }

    /**
     * 求解lca
     * O(log n)
     */
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
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
     * 搞出 fa dep siz son
     */
    void dfs1(int u, int father) {
        fa[u] = father;
        dep[u] = dep[fa[u]] + 1;
        siz[u] = 1;
        for (const auto& neighbor : edge[u]) {
            if (neighbor == father) { // 只准往下走
                continue;
            }

            dfs1(neighbor, u);
            siz[u] += siz[neighbor];           // 更新当前节点的子树大小
            if (siz[son[u]] < siz[neighbor]) { // 寻找重儿子
                son[u] = neighbor;
            }
        }
    }

    /**
     * 第二次dfs
     * 搞出 top id nw
     */
    void dfs2(int u, int t) {
        top[u] = t;
        id[u] = ++cnt;
        nw[cnt] = w[u];
        if (!son[u]) {
            return;
        }
        dfs2(son[u], t);
        for (const auto& neighbor : edge[u]) {
            if (neighbor == fa[u] || neighbor == son[u]) { // 只准往下走 && 不能选刚才走的重儿子
                continue;
            }
            dfs2(neighbor, neighbor);
        }
    }

    inline int lc(int p) {
        return p << 1;
    }

    inline int rc(int p) {
        return p << 1 | 1;
    }

    void pushUp(int p) {
        tree[p].sum = tree[lc(p)].sum + tree[rc(p)].sum;
    }

    void pushDown(int p) {
        if (tree[p].val) {
            tree[lc(p)].sum += tree[p].val * (tree[lc(p)].r - tree[lc(p)].l + 1);
            tree[rc(p)].sum += tree[p].val * (tree[rc(p)].r - tree[rc(p)].l + 1);
            tree[lc(p)].val += tree[p].val;
            tree[rc(p)].val += tree[p].val;
            tree[p].val = 0;
        }
    }

    void build(int p, int s, int t) {
        tree[p] = {s, t, 0, nw[t]};
        if (s == t) {
            return;
        }
        int mid = s + t >> 1;
        build(lc(p), s, mid);
        build(rc(p), mid + 1, t);
        pushUp(p);
    }

    /**
     * 区间加
     */
    void update(int p, int l, int r, const T& k) {
        if (l <= tree[p].l && tree[p].r <= r) {
            tree[p].val += k;
            tree[p].sum += k * (tree[p].r - tree[p].l + 1);
            return;
        }
        pushDown(p);
        int mid = tree[p].l + tree[p].r >> 1;
        if (l <= mid) {
            update(lc(p), l, r, k);
        }
        if (r > mid) {
            update(rc(p), l, r, k);
        }
        pushUp(p);
    }

    /**
     * 将树从u到v结点最短路径上所有节点的值都加上k
     */
    void updatePath(int u, int v, const T& k) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
                std::swap(u, v);
            }
            update(1, id[top[u]], id[u], k);
            u = fa[top[u]];
        }
        if (dep[u] < dep[v]) {
            std::swap(u, v);
        }
        update(1, id[v], id[u], k); // 最后一段
    }

    /**
     * 将以u为根节点的子树内所有节点值都加上k
     */
    void updateTree(int u, const T& k) {
        update(1, id[u], id[u] + siz[u] - 1, k);
    }

    /**
     * 查询区间和
     */
    T query(int p, int l, int r) {
        if (l <= tree[p].l && tree[p].r <= r) {
            return tree[p].sum;
        }
        pushDown(p);
        int mid = tree[p].l + tree[p].r >> 1;
        T ans{};
        if (l <= mid) {
            ans += query(lc(p), l, r);
        }
        if (r > mid) {
            ans += query(rc(p), l, r);
        }
        return ans;
    }

    /**
     * 求树从u到v结点最短路径上所有节点的值之和
     */
    T queryPath(int u, int v) {
        T ans{};
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
                std::swap(u, v);
            }
            ans += query(1, id[top[u]], id[u]);
            u = fa[top[u]];
        }
        if (dep[u] < dep[v]) {
            std::swap(u, v);
        }
        ans += query(1, id[v], id[u]); // 最后一段
        return ans;
    }

    /**
     * 以u为根节点的子树内所有节点值之和
     */
    T queryTree(int u) {
        return query(1, id[u], id[u] + siz[u] - 1);
    }
};

using ll = long long;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<ll> w(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> w[i];
    }
    HLD<ll> hld(n, w);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        hld.addEdge(u, v);
        hld.addEdge(v, u);
    }
    hld.init();
    while (m--) {
        int op, a;
        ll x;
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> a;
            hld.updatePath(x, x, a);
        } else if (op == 2) {
            std::cin >> x >> a;
            hld.updateTree(x, a);
        } else {
            std::cin >> x;
            std::cout << hld.queryPath(x, 1) << std::endl;
        }
    }
}