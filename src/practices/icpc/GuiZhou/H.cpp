#include <bits/stdc++.h>
#include <cstddef>

using i64 = long long;
const int N = 1e5 + 3;

int n, q, a[N], s[N];

struct Node {
    int l, r;
    i64 ll, rr;
    // i64 lazy;
} tr[N << 2];

inline int left_son(int u) { return u << 1; }
inline int right_son(int u) { return u << 1 | 1; }

void push_up(int u) {
    tr[u].ll = std::min(tr[left_son(u)].ll, tr[right_son(u)].ll);    
    tr[u].rr = std::min(tr[left_son(u)].rr, tr[right_son(u)].rr);    
    // tr[u].sum = tr[left_son(u)].sum + tr[right_son(u)].sum;
    // tr[u].cnt = tr[left_son(u)].cnt + tr[right_son(u)].cnt;
}

void push_down(int u) {
    // tr[left_son(u)].sum += tr[left_son(u)].cnt * tr[u].lazy;
    // tr[right_son(u)].sum += tr[right_son(u)].cnt * tr[u].lazy;
    // tr[left_son(u)].lazy += tr[u].lazy;
    // tr[right_son(u)].lazy += tr[u].lazy;
    // tr[u].lazy = 0;
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, a[r], s[r], 0};
    } else {
        tr[u] = {l, r, 0, 0, 0};
        int mid = l + r >> 1;
        build(left_son(u), l, mid);
        build(right_son(u), mid + 1, r);
        push_up(u);
    }
}

void update(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].cnt = v;
        return;
    }
    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) {
        update(left_son(u), x, v);
    } else {
        update(right_son(u), x, v);
    }
    push_up(u);
}

void update(int u, int l, int r, i64 x) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].sum += x * tr[u].cnt;
        tr[u].lazy += x;
        return;
    }

    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) update(left_son(u), l, r, x);
    if (r > mid) update(right_son(u), l, r, x);
    push_up(u);
}

i64 query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].sum;
    }
    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    i64 ans = 0;
    if (l <= mid) ans += query(left_son(u), l, r);
    if (r > mid) ans += query(right_son(u), l, r);
    return ans;
}

int main() {
    int m;
    std::cin >> m;
    while (m--) {
        int op, l, r, z;
        std::cin >> op;
        if (op == 1) {
            std::cin >> l >> r >> z;
        } else {
            std::cin >> l >> r;
        }
    }
}