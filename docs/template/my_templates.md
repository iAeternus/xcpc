# Data Structure 数据结构

## 线段树

### 普通线段树

```cpp
/**
 * @see https://www.luogu.com.cn/problem/P2068
 */
#include <bits/stdc++.h>

using ll = long long;
const int N = 1e5 + 3;
ll a[N];

struct node {
    int l, r;
    ll val, sum;
} tr[N << 2];

inline int left_child(int p) {
    return p << 1;
}

inline int right_child(int p) {
    return p << 1 | 1;
}

inline void push_up(int p) {
    tr[p].val = tr[left_child(p)].val + tr[right_child(p)].val;
}

inline void push_down(int p) {
    if (tr[p].sum) {
        tr[left_child(p)].val += tr[p].sum * (tr[left_child(p)].r - tr[left_child(p)].l + 1);
        tr[right_child(p)].val += tr[p].sum * (tr[right_child(p)].r - tr[right_child(p)].l + 1);
        tr[left_child(p)].sum += tr[p].sum;
        tr[right_child(p)].sum += tr[p].sum;
        tr[p].sum = 0;
    }
}

inline void build(int p, int s, int t) {
    tr[p] = {s, t, 0, 0};
    if(s == t) {
        tr[p].val = a[s];
        return;
    }

    int mid = (s + t) >> 1;
    build(left_child(p), s, mid);
    build(right_child(p), mid + 1, t);
    push_up(p);
}

inline void update(int p, int l, int r, ll k) {
    if(l <= tr[p].l && tr[p].r <= r) {
        tr[p].val += k * (tr[p].r - tr[p].l + 1);
        tr[p].sum += k;
        return;
    }

    push_down(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if(l <= mid) {
        update(left_child(p), l, r, k);
    }
    if(mid < r) {
        update(right_child(p), l, r, k);
    }
    push_up(p);
}

inline ll query(int p, int l, int r) {
    if(l <= tr[p].l && tr[p].r <= r) {
        return tr[p].val;
    }

    push_down(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    ll ans = 0;
    if(l <= mid) {
        ans += query(left_child(p), l, r);
    }
    if(mid < r) {
        ans += query(right_child(p), l, r);
    }
    return ans;
}

int main() {
    int n, w;
    std::cin >> n >> w;
    build(1, 1, N);
    while (w--) {
        char op;
        int a, b;
        std::cin >> op >> a >> b;
        if (op == 'x') {
            update(1, a, a, b);
        } else {
            std::cout << query(1, a, b) << std::endl;
        }
    }
}
```

### 加乘线段树

```cpp
/**
 * @see https://www.luogu.com.cn/problem/P3373
 */
#include <bits/stdc++.h>

using ll = long long;
const int N = 1e5 + 7;
ll a[N];
int n, q, m;

struct node {
    ll val, mul, add;
} t[N << 2];

inline int left_child(int p) {
    return p << 1;
}

inline int right_child(int p) {
    return p << 1 | 1;
}

void push_up(int p) {
    t[p].val = (t[left_child(p)].val + t[right_child(p)].val) % m;
}

void push_down(int p, int l, int r) {
    int mid = (l + r) >> 1;
    t[left_child(p)].val = (t[left_child(p)].val * t[p].mul + t[p].add * (mid - l + 1)) % m;
    t[right_child(p)].val = (t[right_child(p)].val * t[p].mul + t[p].add * (r - mid)) % m;
    t[left_child(p)].add = (t[left_child(p)].add * t[p].mul + t[p].add) % m;
    t[right_child(p)].add = (t[right_child(p)].add * t[p].mul + t[p].add) % m;
    t[left_child(p)].mul = (t[left_child(p)].mul * t[p].mul) % m;
    t[right_child(p)].mul = (t[right_child(p)].mul * t[p].mul) % m;
    t[p].mul = 1;
    t[p].add = 0;
}

void build(int p, int l, int r) {
    t[p] = {0, 1, 0};
    if(l == r) {
        t[p].val = a[l] % m;
        return;
    }

    int mid = (l + r) >> 1;
    build(left_child(p), l, mid);
    build(right_child(p), mid + 1, r);
    push_up(p);
}

void update1(int p, int std_l, int std_r, int l, int r, ll k) {
    if(r < std_l || std_r < l) {
        return;
    }
    if(l <= std_l && std_r <= r) {
        t[p].val = (t[p].val * k) % m;
        t[p].add = (t[p].add * k) % m;
        t[p].mul = (t[p].mul * k) % m;
        return;
    }

    push_down(p, std_l, std_r);
    int mid = (std_l + std_r) >> 1;
    update1(left_child(p), std_l, mid, l, r, k);
    update1(right_child(p), mid + 1, std_r, l, r, k);
    push_up(p);
}

/**
 * [l, r] 区间乘以 k
 */
void update1(int l, int r, ll k) {
    update1(1, 1, n, l, r, k);
}

void update2(int p, int std_l, int std_r, int l, int r, ll k) {
    if(r < std_l || std_r < l) {
        return;
    }
    if(l <= std_l && std_r <= r) {
        t[p].val = (t[p].val + k * (std_r - std_l + 1)) % m;
        t[p].add = (t[p].add + k) % m;
        return;
    }

    push_down(p, std_l, std_r);
    int mid = (std_l + std_r) >> 1;
    update2(left_child(p), std_l, mid, l, r, k);
    update2(right_child(p), mid + 1, std_r, l, r, k);
    push_up(p);
}

/**
 * [l, r] 区间加上 k
 */
void update2(int l, int r, ll k) {
    update2(1, 1, n, l, r, k);
}

ll rangeSum(int p, int std_l, int std_r, int l, int r) {
    if(r < std_l || std_r < l) {
        return 0;
    }
    if(l <= std_l && std_r <= r) {
        return t[p].val;
    }

    push_down(p, std_l, std_r);
    int mid = (std_l + std_r) >> 1;
    return (rangeSum(left_child(p), std_l, mid, l, r) + rangeSum(right_child(p), mid + 1, std_r, l, r)) % m;
}

ll rangeSum(int l, int r) {
    return rangeSum(1, 1, n, l, r);
}

int main() {
    std::cin >> n >> q >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    build(1, 1, n);
    while(q--) {
        int op, x, y;
        ll k;
        std::cin >> op;
        if(op == 1) {
            std::cin >> x >> y >> k;
            update1(x, y, k);
        } else if(op == 2) {
            std::cin >> x >> y >> k;
            update2(x, y, k);
        } else {
            std::cin >> x >> y;
            std::cout << rangeSum(x, y) << std::endl;
        }
    }
}
```



## DSU 并查集

### 普通并查集

```cpp
const int N = 2e4 + 3;
int fa[N];

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int query(int x) {
    while(x != fa[x]) {
        x = fa[x] = fa[fa[x]];
    }
    return x;
}

void merge(int x, int y) {
    int r1 = query(x);
    int r2 = query(y);
    if(r1 != r2) {
        fa[r2] = r1;
    }
}

bool same(int x, int y) {
    return query(x) == query(y);
}
```

### 带权并查集

1. 封装版

   ```cpp
   /**
    * @see https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
    * 封装为结构体
    */
   #include <bits/stdc++.h>
   
   struct Info {
       int min, max, cnt;
   
       Info() {} 
   
       Info(int id)
           : min(id + 1), max(id + 1), cnt(1) {}
   
       void apply(const Info& fy) {
           min = std::min(min, fy.min);
           max = std::max(max, fy.max);
           cnt += fy.cnt;
       }
   };
   
   template <typename Info>
   struct DSU {
       std::vector<int> fa;
       std::vector<Info> info;
   
       DSU() {}
   
       DSU(int n) {
           init(n);
       }
   
       void init(int n) {
           fa.resize(n);
           info.resize(n);
           for(int i = 0; i < n; ++i) {
               fa[i] = i;
               info[i] = Info{i};
           }
       }
   
       int query(int x) {
           while (x != fa[x]) {
               x = fa[x] = fa[fa[x]];
           }
           return x;
       }
   
       bool merge(int x, int y) {
           int fx = query(x);
           int fy = query(y);
           if (fx == fy) {
               return false;
           }
           fa[fy] = fx;
           info[fx].apply(info[fy]);
           return true;
       }
   
       bool same(int x, int y) {
           return query(x) == query(y);
       }
   
       Info get(int x) {
           return info[x];
       }
   };
   
   int main() {
       int n, m;
       std::cin >> n >> m;
       DSU<Info> dsu(n + 1);
       while (m--) {
           std::string op;
           int u, v;
           std::cin >> op;
           if (op == "get") {
               std::cin >> v;
               Info fv = dsu.get(dsu.query(v - 1));
               std::cout << fv.min << ' ' << fv.max << ' ' << fv.cnt << std::endl;
           } else {
               std::cin >> u >> v;
               dsu.merge(u - 1, v - 1);
           }
       }
   }
   ```

2. 简化版（下标从0开始）

   ```cpp
   /**
    * @see https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
    * 下标从 0 开始
    */
   #include <bits/stdc++.h>
   
   const int N = 3e5 + 7;
   
   struct Info {
       int max, min, cnt;
   } info[N];
   
   int fa[N];
   
   void init(int n) {
       for (int i = 0; i < n; ++i) {
           fa[i] = i;
           info[i] = {i + 1, i + 1, 1};
       }
   }
   
   int query(int x) {
       while (x != fa[x]) {
           x = fa[x] = fa[fa[x]];
       }
       return x;
   }
   
   bool merge(int x, int y) {
       int fx = query(x);
       int fy = query(y);
       if (fx == fy) {
           return false;
       }
       fa[fy] = fx;
       info[fx].max = std::max(info[fx].max, info[fy].max);
       info[fx].min = std::min(info[fx].min, info[fy].min);
       info[fx].cnt += info[fy].cnt;
       return true;
   }
   
   bool same(int x, int y) {
       return query(x) == query(y);
   }
   
   int main() {
       int n, m;
       std::cin >> n >> m;
       init(n);
       while (m--) {
           std::string op;
           int u, v;
           std::cin >> op;
           if (op == "get") {
               std::cin >> v;
               int fv = query(v - 1);
               std::cout << info[fv].min << ' ' << info[fv].max << ' ' << info[fv].cnt << std::endl;
           } else {
               std::cin >> u >> v;
               merge(u - 1, v - 1);
           }
       }
   }
   ```

3. 简化版（下标从1开始）

   ```cpp
   /**
    * @see https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
    * 下标从 1 开始
    */
   #include <bits/stdc++.h>
   
   const int N = 3e5 + 7;
   
   struct Info {
       int max, min, cnt;
   } info[N];
   
   int fa[N];
   
   void init(int n) {
       for (int i = 1; i <= n; ++i) {
           fa[i] = i;
           info[i] = {i, i, 1};
       }
   }
   
   int query(int x) {
       while (x != fa[x]) {
           x = fa[x] = fa[fa[x]];
       }
       return x;
   }
   
   bool merge(int x, int y) {
       int fx = query(x);
       int fy = query(y);
       if (fx == fy) {
           return false;
       }
       fa[fy] = fx;
       info[fx].max = std::max(info[fx].max, info[fy].max);
       info[fx].min = std::min(info[fx].min, info[fy].min);
       info[fx].cnt += info[fy].cnt;
       return true;
   }
   
   bool same(int x, int y) {
       return query(x) == query(y);
   }
   
   int main() {
       int n, m;
       std::cin >> n >> m;
       init(n);
       while (m--) {
           std::string op;
           int u, v;
           std::cin >> op;
           if (op == "get") {
               std::cin >> v;
               int fv = query(v);
               std::cout << info[fv].min << ' ' << info[fv].max << ' ' << info[fv].cnt << std::endl;
           } else {
               std::cin >> u >> v;
               merge(u, v);
           }
       }
   }
   ```

## heap

```cpp
std::priority_queue<int, std::vector<int>, std::less<int>> pq; // less表示按照递减(从大到小)的顺序插入元素
std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // greater表示按照递增（从小到大）的顺序插入元素
```



# Graph 图论

## 链式前向星

```cpp
const int N = 1e5 + 3;

int head[N], tot;

struct node {
    int to, next;
} edge[N << 1];

void addEdge(int u, int v) {
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}

// 遍历x的邻接节点
for(int i = head[x]; i; i = edge[i].next) {
    
}
```



## 二分图最大权匹配

```cpp
/**
 * @see https://www.luogu.com.cn/problem/B3605
 */
#include <bits/stdc++.h>

const int N = 2.5e5 + 3;

int head[N], tot;

struct node {
    int to, next;
} edge[N << 1];

void addEdge(int u, int v) {
    edge[++tot] = {v, head[u]};
    head[u] = tot;
}

bool vis[N];
int match[N];

bool dfs(int x) {
    for(int i = head[x]; i; i = edge[i].next) {
        int to = edge[i].to;
        if(!vis[to]) {
            vis[to] = true;
            if(!match[to] || dfs(match[to])) {
                match[to] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nl, nr, m;
    std::cin >> nl >> nr >> m;
    while(m--) {
        int u, v;
        std::cin >> u >> v;
        addEdge(u, v);
    }

    int ans = 0;
    for(int i = 1; i <= nl; ++i) {
        ans += dfs(i);
        memset(vis, 0, sizeof(vis));
    }
    std::cout << ans << std::endl;
}
```

## 最近公共组先LCA

### 树链剖分求LCA

```cpp
/**
 * 树链剖分求LCA
 * @see https://blog.csdn.net/qq_41418281/article/details/108220247
 */
#include <bits/stdc++.h>

struct HLD {
    int n;                               // 节点个数
    std::vector<std::vector<int>> edge;  // 邻接矩阵
    std::vector<int> siz;                // siz[u]: 存以u为根的子树的结点数
    std::vector<int> dep;                // dep[u]: 存u的深度
    std::vector<int> top;                // top[u]: 存u所在重链的顶点
    std::vector<int> son;                // son[u]: 存u的重儿子
    std::vector<int> fa;                 // fa[u]: 存u的父节点

    HLD(int n) {
        this->n = n;
        edge.resize(n + 1);
        siz.resize(n + 1);
        dep.resize(n + 1);
        top.resize(n + 1);
        son.resize(n + 1);
        fa.resize(n + 1);
    }

    /**
     * 添加边
     */
    void addEdge(int u, int v) {
        edge[u].push_back(v);
    }

    /**
     * 遍历u的邻接结点
     */
    void forEach(int u, const std::function<void(int)>& func) {
        for (auto& n : edge[u]) {
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
     */
    void dfs1(int u, int father) {
        fa[u] = father;
        dep[u] = dep[fa[u]] + 1;
        siz[u] = 1;
        for (const auto& neighbor : edge[u]) {
            if (neighbor == fa[u]) {
                continue;
            }

            dfs1(neighbor, u);
            // 更新当前节点的子树大小
            siz[u] += siz[neighbor];
            // 寻找重儿子
            if (siz[neighbor] > siz[son[u]]) {
                son[u] = neighbor;
            }
        }
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
        for(const auto& neighbor : edge[u]) {
            if (neighbor == fa[u] || neighbor == son[u]) {
                continue;
            }
            dfs2(neighbor, neighbor);
        }
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
        h.addEdge(v, u);
    }

    h.init(s);

    while (m--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << h.lca(a, b) << std::endl;
    }
}
```

## 树链剖分HLD + 树上修改（HLD + 线段树）

```cpp
/**
 * @see https://www.luogu.com.cn/problem/P3384
 * 树上修改与查询
 * 闭区间，下标从1开始
 */
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
    int n;                               // 节点个数
    std::vector<T> w;                    // 节点权值
    std::vector<std::vector<int>> edge;  // 树边
    std::vector<int> fa;                 // fa[u]: 存u的父节点
    std::vector<int> dep;                // dep[u]: 存u的深度
    std::vector<int> son;                // son[u]: 存u的重儿子
    std::vector<int> siz;                // siz[u]: 存以u为根的子树的结点数
    std::vector<int> top;                // top[u]: 存u所在重链的顶点

    // 树上修改相关数据
    int cnt;                 // 新编号计数
    std::vector<int> id;     // id[u]: 存u剖分后的新编号
    std::vector<T> nw;       // 存新编号在树中所对应节点的权值
    std::vector<Node> tree;  // 线段树

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
        tree.resize(n << 2);  // 4n
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
            if (neighbor == father) {  // 只准往下走
                continue;
            }

            dfs1(neighbor, u);
            siz[u] += siz[neighbor];            // 更新当前节点的子树大小
            if (siz[son[u]] < siz[neighbor]) {  // 寻找重儿子
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
            if (neighbor == fa[u] || neighbor == son[u]) {  // 只准往下走 && 不能选刚才走的重儿子
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
        update(1, id[v], id[u], k);  // 最后一段
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
        ans += query(1, id[v], id[u]);  // 最后一段
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
    int n, m, r;
    ll p;
    std::cin >> n >> m >> r >> p;
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

    hld.init(r);

    while (m--) {
        int op, x, y;
        ll z;
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y >> z;
            hld.updatePath(x, y, z);
        } else if (op == 2) {
            std::cin >> x >> y;
            std::cout << hld.queryPath(x, y) % p << std::endl;
        } else if (op == 3) {
            std::cin >> x >> z;
            hld.updateTree(x, z);
        } else if (op == 4) {
            std::cin >> x;
            std::cout << hld.queryTree(x) % p << std::endl;
        }
    }
}
```



