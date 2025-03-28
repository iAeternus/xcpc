# 数据结构

## 树状数组

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

## 并查集

## 单调栈

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



