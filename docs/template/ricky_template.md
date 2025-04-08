# 基本算法

### 二分

最小值最大 -> 答案在左边 -> 满足check时压缩右边界 -> 二分出来的答案一定在**l**上

```cpp
while(l <= r) {
    int mid = l + r >> 1;
    if(check(mid)) r = mid - 1;
    else l = mid + 1;
}
l
```

最大值最小 -> 答案在右边 -> 满足check时压缩左边界 -> 二分出来的答案一定在**r**上

```cpp
while(l <= r) {
    int mid = l + r >> 1;
    if(check(mid)) l = mid + 1;
    else r = mid - 1;
}
r
```



# 数据结构

## 树状数组

```cpp
/**
 * 树状数组（Fenwick Tree/BIT）实现区间最值
 * - 核心思想：利用二进制索引特性，每个节点存储特定区间的统计值
 * - 适用场景：单点更新 + 区间查询（最值/求和）
 * - 时间复杂度：O(n log n) 建树，O(log n) 更新/查询
 * 
 * 模板说明：
 * 1. 修改合并方式：将 std::max 改为其他操作（如加法、最小值）
 * 2. 修改数据存储：a[] 存储原始数据，tree[] 存储区间统计值
 * 3. 注意最值操作的局限性：无法高效处理区间覆盖更新
 */

const int N = 2e5 + 10;
/**
 * 初始化 memset(tree, 0, sizeof tree);
 */
int n, m, a[N], tree[N];

int lowbit(int x) {
    return x & -x;
}

/**
 * 单点更新：更新所有包含x的区间
 * 初始化建树时 update(i, a[i]);
 */
void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tree[x] = val;
        for (int i = 1; i < lowbit(x); i <<= 1) {
            tree[x] = std::max(tree[x], tree[x - i]);
        }
    }
}

/**
 * 区间查询：从右往左合并区间
 */
int query(int l, int r) {
    int ans = 0;
    while (r >= l) {
        ans = std::max(ans, a[r]); // 先比较原始数据
        --r;                       // 移动到下一个待处理位置
        // 如果剩余区间可以跳跃到前一个块
        while (r - lowbit(r) >= l) {
            ans = std::max(ans, tree[r]);
            r -= lowbit(r);
        }
    }
    return ans;
}
```

## 线段树

```cpp
const int N = 2e5 + 5;
i64 a[N];

struct Node {
    int l, r;
    i64 max_val; // 根据需求修改val的类型和合并方式
} tree[N << 2];

inline int left_son(int x) { return x << 1; }
inline int right_son(int x) { return x << 1 | 1; }

/**
 * 合并左右子节点，示例最大值
 */
void push_up(int root) {
    tree[root].max_val = std::max(tree[left_son(root)].max_val, tree[right_son(root)].max_val);
}

/**
 * 建树
 * build(1, 1, n);
 */
void build(int root, int l, int r) {
    tree[root].l = l;
    tree[root].r = r;
    if (l == r) {
        tree[root].max_val = a[l]; // 初始化叶子节点
        return;
    }
    int mid = (l + r) >> 1;
    build(left_son(root), l, mid);
    build(right_son(root), mid + 1, r);
    push_up(root);
}

/**
 * 单点更新
 */
void update(int root, int pos, i64 val) {
    if (tree[root].l == tree[root].r) {
        tree[root].max_val = val;
        return;
    }
    int mid = (tree[root].l + tree[root].r) >> 1;
    if (pos <= mid) {
        update(left_son(root), pos, val);
    } else {
        update(right_son(root), pos, val);
    }
    push_up(root);
}

/**
 * 区间查询
 */
i64 query(int root, int L, int R) {
    if (L <= tree[root].l && tree[root].r <= R) {
        return tree[root].max_val;
    }
    int mid = (tree[root].l + tree[root].r) >> 1;
    i64 max_val = 0; // 初始值需根据操作类型设定，如求和为0，最大为-INF等
    if (L <= mid) max_val = std::max(max_val, query(left_son(root), L, R));
    if (R > mid) max_val = std::max(max_val, query(right_son(root), L, R));
    return max_val;
}
```



## ST 表

写 `st` 表大概率要 **关闭同步流**

```cpp
/**
 * st表用于解决可重复贡献问题
 * 设有一个二元运算 op(x, y) ，满足 op(a, a) = a，则称op为可重复贡献的
 * 显然最大值、最小值、最大公因数、最小公倍数、按位或、按位与都符合这个条件
 * 
 * std::__lg(x) 函数时间复杂度为 O(1)
 */

const int N = 5e4 + 3;
// 原数组a, 最大值st表Max，最小值st表Min
// 这里为了内存局部性将较小者作为行数
int a[N], Max[std::__lg(N) + 1][N], Min[std::__lg(N) + 1][N];

/**
 * 初始化st表
 * st[i][j]: 表示闭区间 [i, i + 2^j - 1] 的操作结果
 * 显然 st[i][0] = ai
 * 
 * st[i][j] = op( st[i][j - 1], st[i + 2^(j-1)][i - 1] )
 */
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        Max[0][i] = a[i];
        Min[0][i] = a[i];
    }
    for (int i = 1; i <= std::__lg(n); ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Max[i][j] = std::max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
            Min[i][j] = std::min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
        }
    }
}

/**
 * 区间查询
 * s = floor(log_2(r - l + 1))
 * 将区间分为两部分 [l, l + 2^s - 1] 与 [r - 2^s + 1, r]
 * op两部分结果
 */
int query(int l, int r) {
    int s = std::__lg(r - l + 1);
    return std::max(Max[s][l], Max[s][r - (1 << s) + 1]);
}

int query2(int l, int r) {
    int s = std::__lg(r - l + 1);
    return std::min(Min[s][l], Min[s][r - (1 << s) + 1]);
}
```

```cpp
/**
 * 特别地，可动态追加的st表
 * 用于求解数组初始为空不断追加的问题
 * 与init系出同源
 */
void insert(int val) {
    len++;
    st[0][len] = val;
    for (int s = 1; (1 << s) <= len; s++) {
        int start = len - (1 << s) + 1;
        if (start < 1) break;
        st[s][start] = std::max(st[s - 1][start], st[s - 1][start + (1 << (s - 1))]);
    }
}
```

**better**

```cpp
/**
 * @see https://codeforces.com/problemset/problem/622/C
 */
#include <bits/stdc++.h>

template <typename T>
struct St {
    int n;
    std::vector<T> a;                 // 下标从1开始
    std::vector<std::vector<T>> st;   // ST表
    const std::function<T(T, T)> cmp; // 比较规则

    St(int n, const std::vector<T>& _a, std::function<T(T, T)> _cmp) :
            n(n), a(_a), cmp(_cmp) {
        assert(a.size() > n);

        const int LG = std::__lg(n);
        st.assign(LG + 1, std::vector<T>(n + 1));

        for (int i = 1; i <= n; i++) {
            st[0][i] = i;
        }

        for (int j = 1; j <= LG; j++) {
            for (int i = 1; i <= n - (1 << j) + 1; i++) {
                st[j][i] = cmp(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
            }
        }
    }

    /**
     * 区间查询
     */
    T query(int l, int r) {
        int k = std::__lg(r - l + 1);
        return cmp(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    auto rmqMin = St<int>(n, a, [&](int i, int j) {
        return a[i] < a[j] ? i : j;
    });
    auto rmqMax = St<int>(n, a, [&](int i, int j) {
        return a[i] > a[j] ? i : j;
    });

    while (m--) {
        int l, r, x;
        std::cin >> l >> r >> x;

        int minidx = rmqMin.query(l, r), maxidx = rmqMax.query(l, r);
        if (a[minidx] == a[maxidx] && a[minidx] == x) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << (a[minidx] != x ? minidx : maxidx) << std::endl;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
}
```

## 并查集

## 单调栈

* 从栈底到栈顶严格单调递减，可以找到当前栈顶对应元素在原序列中右边最近的比该元素大的元素
* 单调栈中可以存下标，视题目而定

```cpp
while(!st.empty() && st.top() <= x) {
    st.pop();
}
```

## 平衡二叉树

### 替罪羊树

### `Treap`

### 伸展树

## 树链剖分

# **图论**

// TODO

# **字符串**

## 字典树（`Trie`）

## KMP 算法

## `Manacher` 算法

## 后缀数组

## 字符串哈希

# **杂项**

## 基本 `cf` 模板

```cpp
#include <bits/stdc++.h>

using i64 = long long;

void solve() {

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
```

## **快读**

```cpp
inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
```



