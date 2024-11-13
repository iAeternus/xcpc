#include <bits/stdc++.h>

typedef std::pair<int, int> pii;
const int N = 1e5 + 10;

struct Tree {
    int l, r;
    int num0, num1, cnt;
} tr[N << 2];

void change(int u) {
    std::swap(tr[u].num0, tr[u].num1);
    tr[u].cnt ^= 1;
}

void pushup(int u) {
    tr[u].num0 = tr[u << 1].num0 + tr[u << 1 | 1].num0;
    tr[u].num1 = tr[u << 1].num1 + tr[u << 1 | 1].num1;
}

void pushdown(int u) {
    if (tr[u].cnt == 1) {
        change(u << 1);
        change(u << 1 | 1);
        tr[u].cnt ^= 1;
    }
}

void build(int u, int l, int r) {
    if (l == r)
        tr[u] = {l, r, 1, 0, 0};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        change(u);
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        modify(u << 1, l, r);
    if (r > mid)
        modify(u << 1 | 1, l, r);
    pushup(u);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].num1;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (l <= mid)
        res += query(u << 1, l, r);
    if (r > mid)
        res += query(u << 1 | 1, l, r);
    return res;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    build(1, 1, n);
    while(m--) {
        int op, l, r;
        std::cin >> op >> l >> r;
        if(op == 0) {
            modify(1, l, r);
        } else {
            std::cout << query(1, l, r) << std::endl;
        }
    }
}