/**
 * @see https://www.luogu.com.cn/problem/P3958
 */
#include <bits/stdc++.h>

using ll = long long;
const int N = 1e3 + 5;
int fa[N];

struct Point {
    ll x, y, z;
};

ll distSqr(const Point& p1, const Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z);
}

bool isIntersect(const Point& p1, const Point& p2, ll r) {
    return distSqr(p1, p2) <= 4 * r * r;
}

bool isDown(const Point& p, ll r) {
    return p.z <= r;
}

bool isUp(const Point& p, ll r, ll h) {
    return p.z >= h - r;
}

void init(int n) {
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
    }
}

int query(int x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = query(fa[x]);
}

void merge(int x, int y) {
    int r1 = query(x);
    int r2 = query(y);
    if (r1 != r2) {
        fa[r2] = r1;
    }
}

bool same(int x, int y) {
    return query(x) == query(y);
}

std::vector<int> down, up;
std::vector<Point> total;

void solve() {
    down.clear();
    up.clear();
    total.clear();
    int n;
    ll h, r;
    std::cin >> n >> h >> r;
    init(n);
    for (int i = 0; i < n; ++i) {
        ll x, y, z;
        std::cin >> x >> y >> z;
        Point p{x, y, z};
        total.push_back(p);
        if (isDown(p, r)) {
            down.push_back(i);
        }
        if (isUp(p, r, h)) {
            up.push_back(i);
        }

        for (int j = 0; j < i; ++j) {
            if (isIntersect(total[i], total[j], r)) {
                merge(i, j);
            }
        }
    }

    for (int i = 0; i < down.size(); ++i) {
        for (int j = 0; j < up.size(); ++j) {
            if (same(i, j)) {
                std::cout << "Yes" << std::endl;
                return;
            }
        }
    }
    std::cout << "No" << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}