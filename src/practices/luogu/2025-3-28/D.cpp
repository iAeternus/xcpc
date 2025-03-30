#include <bits/stdc++.h>

using i64 = long long;
const int N = 1e6 + 10;
i64 a[N];

struct Node {
    int l, r;
    i64 min_val;
    i64 lazy;
} tree[N << 2];

inline int left_son(int x) { return x << 1; }
inline int right_son(int x) { return x << 1 | 1; }

void push_up(int root) {
    tree[root].min_val = std::min(tree[left_son(root)].min_val,
                                  tree[right_son(root)].min_val);
}

void push_down(int root) {
    if (tree[root].lazy) {
        auto& left = tree[left_son(root)];
        auto& right = tree[right_son(root)];
        left.min_val += tree[root].lazy;
        left.lazy += tree[root].lazy;

        right.min_val += tree[root].lazy;
        right.lazy += tree[root].lazy;

        tree[root].lazy = 0;
    }
}

void build(int root, int l, int r) {
    tree[root].l = l;
    tree[root].r = r;
    tree[root].lazy = 0;

    if (l == r) {
        tree[root].min_val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(left_son(root), l, mid);
    build(right_son(root), mid + 1, r);
    push_up(root);
}

void range_update(int root, int L, int R, i64 val) {
    if (L > tree[root].r || R < tree[root].l) return;

    if (L <= tree[root].l && tree[root].r <= R) {
        tree[root].min_val += val;
        tree[root].lazy += val;
        return;
    }

    push_down(root);
    range_update(left_son(root), L, R, val);
    range_update(right_son(root), L, R, val);
    push_up(root);
}

i64 query_min(int root, int L, int R) {
    if (L > tree[root].r || R < tree[root].l) return LLONG_MAX;

    if (L <= tree[root].l && tree[root].r <= R) {
        return tree[root].min_val;
    }

    push_down(root);
    return std::min(query_min(left_son(root), L, R),
                    query_min(right_son(root), L, R));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    build(1, 1, n);

    for (int idx = 1; idx <= m; ++idx) {
        i64 d, s, t;
        std::cin >> d >> s >> t;
        range_update(1, s, t, -d);
        i64 min_val = query_min(1, s, t);

        if (min_val < 0) {
            std::cout << "-1\n";
            std::cout << idx << std::endl;
            return 0;
        }
    }

    std::cout << "0";
}
