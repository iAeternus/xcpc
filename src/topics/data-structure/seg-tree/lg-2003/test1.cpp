/**
 * @see https://www.luogu.com.cn/problem/P2003
 * TODO WA!!!!
 */
#include <bits/stdc++.h>

const int N = 1e4 + 7;

int n;

struct leb {
    int y, x1, x2;
} a[N];

struct node {
    int l, r, val, max;
} tr[N << 2];

inline int left_child(int p) {
    return p << 1;
}

inline int right_child(int p) {
    return p << 1 | 1;
}

void push_up(int p) {
    tr[p].val = std::max(tr[left_child(p)].val, tr[right_child(p)].val);
}

void push_down(int p) {
    int w = tr[p].max;
    tr[left_child(p)].val = std::max(tr[left_child(p)].val, w);
    tr[right_child(p)].val = std::max(tr[right_child(p)].val, w);
    tr[left_child(p)].max = std::max(tr[left_child(p)].max, w);
    tr[right_child(p)].max = std::max(tr[right_child(p)].max, w);
    tr[p].max = 0;
}

void build(int p, int s, int t) {
    tr[p] = {s, t, a[s].y, 0};
    if (s == t) {
        return;
    }

    int mid = (s + t) >> 1;
    build(left_child(p), s, mid);
    build(right_child(p), mid + 1, t);
    push_up(p);
}

int query(int p, int s, int t, int l, int r) {
    if (r < s || t < l) {
        return 0;
    }
    if (l <= s && t <= r) {
        return tr[p].val;
    }

    push_down(p);
    int mid = (s + t) >> 1;
    return std::max(query(left_child(p), s, mid, l, r), query(right_child(p), mid + 1, t, l, r));
}

int query(int l, int r) {
    return query(1, 1, n, l, r);
}

void update(int p, int s, int t, int l, int r, int k) {
    if (r < s || t < l) {
        return;
    }
    if (l <= s && t <= r) {
        tr[p].val = std::max(tr[p].val, k);
        tr[p].max = std::max(tr[p].max, k);
        return;
    }

    push_down(p);
    int mid = (s + t) >> 1;
    update(left_child(p), s, mid, l, r, k);
    update(right_child(p), mid + 1, t, l, r, k);
    push_up(p);
}

void update(int l, int r, int k) {
    update(1, 1, n, l, r, k);
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i].y >> a[i].x1 >> a[i].x2;
    }

    std::sort(a + 1, a + n + 1, [](const leb& o1, const leb& o2) {
        return o1.y < o2.y;
    });
    build(1, 1, N);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int l = a[i].x1, r = a[i].x2;
        ans += (a[i].y - query(l, l + 1)); // 左侧边界
        ans += (a[i].y - query(r - 1, r)); // 右侧边界
        update(l + 1, r - 1, a[i].y);
    }

    std::cout << ans << std::endl;
}