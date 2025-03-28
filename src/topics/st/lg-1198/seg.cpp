#include <bits/stdc++.h>

using i64 = long long;
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m, d;
    std::cin >> m >> d;
    build(1, 1, m);
    int pos = 0, t = 0;
    while (m--) {
        char c;
        i64 n;
        std::cin >> c >> n;
        if (c == 'A') {
            n = (n + t) % d;
            update(1, ++pos, n);
        } else {
            t = query(1, pos - n + 1, pos);
            std::cout << t << '\n';
        }
    }
}
