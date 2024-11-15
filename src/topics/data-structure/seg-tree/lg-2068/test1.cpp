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