/**
 * @see https://www.luogu.com.cn/problem/P3870
 */
#include <bits/stdc++.h>

using ll = long long;

const int N = 1e6 + 5;
ll a[N];

struct node {
    int l, r;
    ll sum;
} tree[N << 2];

int left_son(int x) {
    return x << 1;
}

int right_son(int x) {
    return x << 1 | 1;
}

int get_mid(int l, int r) {
    return l + ((r - l) >> 1);
}

void push_up(int root) {
    tree[root].sum = tree[left_son(root)].sum + tree[right_son(root)].sum;
}

void build(int root, int l, int r) {
    tree[root].l = l;
    tree[root].r = r;
    if (l == r) {
        tree[root].sum = a[l];
        return;
    }
    int mid = get_mid(l, r);
    build(left_son(root), l, mid);
    build(right_son(root), mid + 1, r);
    push_up(root);
}

void update(int root, int l, int r) {
    if (tree[root].l == tree[root].r) {
        tree[root].sum = sqrt(tree[root].sum);
        return;
    }
    if (tree[root].sum <= tree[root].r - tree[root].l + 1) {
        return;
    }
    int mid = get_mid(tree[root].l, tree[root].r);
    if (mid >= l) {
        update(left_son(root), l, r);
    }
    if (mid < r) {
        update(right_son(root), l, r);
    }
    push_up(root);
}

ll query(int root, int l, int r) {
    if (l <= tree[root].l && tree[root].r <= r) {
        return tree[root].sum;
    }
    int mid = get_mid(tree[root].l, tree[root].r);
    ll sum = 0;
    if (mid >= l) {
        sum += query(left_son(root), l, r);
    }
    if (mid < r) {
        sum += query(right_son(root), l, r);
    }
    return sum;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    build(0, 0, n);
    while(m--) {
        int op, l, r;
        std::cin >> op >> l >> r;
        if(op == 0) {
            update(1, l, r);
        } else {
            std::cout << query(1, l, r) << std::endl;
        }
    }
}