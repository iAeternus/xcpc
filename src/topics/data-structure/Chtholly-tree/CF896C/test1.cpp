#include <bits/stdc++.h>

using i64 = long long;

struct Node {
    i64 l, r;
    mutable i64 v;

    Node(i64 l, i64 r, i64 v) :
            l(l), r(r), v(v) {}

    bool operator<(const Node& o) const {
        return l < o.l;
    }
};

std::set<Node> tree;

auto split(int x) {
    auto it = tree.lower_bound({x, 0, 0});
    if (it != tree.end() && it->l == x) return it;
    --it;
    int l = it->l, r = it->r, v = it->v;
    tree.erase(it);
    tree.insert({l, x - 1, v});
    return tree.insert({x, r, v}).first;
}

void assign(i64 l, i64 r, i64 v) {
    auto end = split(r + 1), begin = split(l);
    tree.erase(begin, end);
    tree.insert({l, r, v});
}

i64 n, m, seed, vmax;

i64 rnd() {
    i64 ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}

void get_data(i64& op, i64& l, i64& r, i64& x, i64& y) {
    op = rnd() % 4 + 1;
    l = rnd() % n + 1;
    l = rnd() % n + 1;

    if (l > r) {
        std::swap(l, r);
    }

    if (op == 3) {
        x = (rnd() % (r - l + 1)) + 1;
    } else {
        x = (rnd() % vmax) + 1;
    }

    if (op == 4) {
        y = (rnd() % vmax) + 1;
    }
}

i64 qpow(i64 a, i64 n, i64 p) {
    i64 ans = 1;
    a %= p;
    while (n) {
        if (n & 1) ans = ans * a % p;
        n >>= 1;
        a = a * a % p;
    }
    return ans;
}

void add(i64 l, i64 r, i64 v) {
    auto end = split(r + 1);
    for (auto it = split(l); it != end; ++it) {
        it->v += v;
    }
}

i64 kth(i64 l, i64 r, i64 k) {
    auto end = split(r + 1);
    std::vector<std::pair<i64, i64>> v;
    for (auto it = split(l); it != end; ++it) {
        v.push_back(std::make_pair(it->v, it->r - it->l + 1));
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        k -= v[i].second;
        if (k <= 0) {
            return v[i].first;
        }
    }
}

i64 sum_of_pow(i64 l, i64 r, i64 x, i64 y) {
    i64 tot = 0;
    auto end = split(r + 1);
    for (auto it = split(l); it != end; ++it) {
        tot = (tot + qpow(it->v, x, y) * (it->r - it->l + 1)) % y;
    }
    return tot;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m >> seed >> vmax;
    for (int i = 0; i < n; ++i) {
        int r = rnd();
        tree.insert({i, i, r % vmax + 1});
    }

    while (m--) {
        i64 op, l, r, x, y;
        get_data(op, l, r, x, y);

        switch (op) {
        case 1:
            add(l, r, x);
            break;
        case 2:
            assign(l, r, x);
            break;
        case 3:
            std::cout << kth(l, r, x) << std::endl;
            break;
        case 4:
            std::cout << sum_of_pow(l, r, x, y) << std::endl;
            break;
        }
    }
}