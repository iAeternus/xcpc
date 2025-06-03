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
    if (l == r) {
        t[p].val = a[l] % m;
        return;
    }

    int mid = (l + r) >> 1;
    build(left_child(p), l, mid);
    build(right_child(p), mid + 1, r);
    push_up(p);
}

void update1(int p, int std_l, int std_r, int l, int r, ll k) {
    if (r < std_l || std_r < l) {
        return;
    }
    if (l <= std_l && std_r <= r) {
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
    if (r < std_l || std_r < l) {
        return;
    }
    if (l <= std_l && std_r <= r) {
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
    if (r < std_l || std_r < l) {
        return 0;
    }
    if (l <= std_l && std_r <= r) {
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
    while (q--) {
        int op, x, y;
        ll k;
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y >> k;
            update1(x, y, k);
        } else if (op == 2) {
            std::cin >> x >> y >> k;
            update2(x, y, k);
        } else {
            std::cin >> x >> y;
            std::cout << rangeSum(x, y) << std::endl;
        }
    }
}