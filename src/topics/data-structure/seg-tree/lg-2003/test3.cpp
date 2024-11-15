/**
 * @see https://www.luogu.com.cn/problem/P2003
 */
#include <bits/stdc++.h>

const int N = 1e4 + 7;

struct leb {
    int y, x1, x2;
} a[N];

struct node {
    int l, r, v, max;
} tr[N << 2];

inline int left_child(int p) {
    return p << 1;
}

inline int right_child(int p) {
    return p << 1 | 1;
}

inline void push_up(int p) {
    tr[p].v = std::max(tr[left_child(p)].v, tr[right_child(p)].v);
}

inline void push_down(int p) {
    int w = tr[p].max;
    tr[left_child(p)].v = std::max(tr[left_child(p)].v, w);
    tr[left_child(p)].max = std::max(tr[left_child(p)].max, w);
    tr[right_child(p)].v = std::max(tr[right_child(p)].v, w);
    tr[right_child(p)].max = std::max(tr[right_child(p)].max, w);
    tr[p].max = 0;
}

inline void build(int p, int s, int t) {
    tr[p] = {s, t, 0, 0};
    if (s == t) {
        return;
    }
    int mid = (s + t) >> 1;
    build(left_child(p), s, mid);
    build(right_child(p), mid + 1, t);
}

inline int query(int p, int l, int r) {
    int s = tr[p].l, t = tr[p].r;
    if (l == s && r == t)  return tr[p].v;

    if (tr[p].max) push_down(p);
    int mid = (s + t) >> 1;
    if (r <= mid) return query(left_child(p), l, r);
    else if (l > mid) return query(right_child(p), l, r);
    else return std::max(query(left_child(p), l, mid), query(right_child(p), mid + 1, r));
}

inline void update(int p, int l, int r, int k) {
    int s = tr[p].l, t = tr[p].r;
    if(l == s && r == t) {
        tr[p].v = std::max(tr[p].v, k);
        tr[p].max = k;
        return;
    }

    if(tr[p].max) push_down(p);
    int mid = (s + t) >> 1;
    if(r <= mid) update(left_child(p), l, r, k);
    else if(l > mid) update(right_child(p), l, r, k);
    else {
        update(left_child(p), l, mid, k);
        update(right_child(p), mid + 1, r, k);
    }
    push_up(p);
}

int main() {
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i].y >> a[i].x1 >> a[i].x2;
    }

    std::sort(a + 1, a + n + 1, [](const leb& o1, const leb& o2) {
        return o1.y < o2.y;
    });
    build(1, 1, N);

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int l = a[i].x1, r = a[i].x2;
        ans += (a[i].y - query(1, l, l + 1)); // 左侧边界
        ans += (a[i].y - query(1, r - 1, r)); // 右侧边界
        update(1, l + 1, r - 1, a[i].y);
    }

    std::cout << ans << std::endl;
}