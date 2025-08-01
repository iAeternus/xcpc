#include <bits/stdc++.h>

constexpr int inf = 0x3f3f3f3f;

struct Tag {
    int x = 0;
    void apply(const Tag& t) & {
        // x = std::max(x, t.x);
        x += t.x;
    }
};

struct Info {
    int x = 0, l, r;
    void apply(const Tag& t) & {
        // x = std::max(x, t.x);
        x += t.x * (r - l);
    }

    constexpr Info& operator=(const Info& info) {
        this->x = info.x;
        this->l = info.l;
        this->r = info.r;
        return *this;
    }
};

Info operator+(const Info& a, const Info& b) {
    // return {std::max(a.x, b.x)};
    return {a.x + b.x};
}

// template <class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    LazySegmentTree() :
            n(0) {}

    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    template <class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }

    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }

    template <class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = {init_[l]};
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pushUp(p);
        };
        build(1, 0, n);
    }

    void pushUp(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void apply(int p, const Tag& v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void pushDown(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag{};
    }

    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        pushDown(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pushUp(p);
    }

    void modify(int p, const Info& v) {
        modify(1, 0, n, p, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info{};
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        pushDown(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        pushDown(p);
        int m = (l + r) / 2;
        if (l <= m) {
            rangeApply(2 * p, l, m, x, y, v);
        }
        if (m < r) {
            rangeApply(2 * p + 1, m, r, x, y, v);
        }
        pushUp(p);
    }

    void rangeApply(int l, int r, const Tag& v) {
        rangeApply(1, 0, n, l, r, v);
    }

    // void half(int p, int l, int r) {
    //     if (info[p].act == 0) {
    //         return;
    //     }
    //     if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {
    //         apply(p, {-(info[p].min + 1) / 2});
    //         return;
    //     }
    //     int m = (l + r) / 2;
    //     pushDown(p);
    //     half(2 * p, l, m);
    //     half(2 * p + 1, m, r);
    //     pushUp(p);
    // }

    // void half() {
    //     half(1, 0, n);
    // }

    template <class F>
    int findFirst(int p, int l, int r, int x, int y, F&& pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        pushDown(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }

    template <class F>
    int findFirst(int l, int r, F&& pred) {
        return findFirst(1, 0, n, l, r, pred);
    }

    template <class F>
    int findLast(int p, int l, int r, int x, int y, F&& pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        pushDown(p);
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }

    template <class F>
    int findLast(int l, int r, F&& pred) {
        return findLast(1, 0, n, l, r, pred);
    }

    // void maintainL(int p, int l, int r, int pre) {
    //     if (info[p].difl > 0 && info[p].maxlowl < pre) {
    //         return;
    //     }
    //     if (r - l == 1) {
    //         info[p].max = info[p].maxlowl;
    //         info[p].maxl = info[p].maxr = l;
    //         info[p].maxlowl = info[p].maxlowr = -inf;
    //         return;
    //     }
    //     int m = (l + r) / 2;
    //     pushDown(p);
    //     maintainL(2 * p, l, m, pre);
    //     pre = max(pre, info[2 * p].max);
    //     maintainL(2 * p + 1, m, r, pre);
    //     pushUp(p);
    // }

    // void maintainL() {
    //     maintainL(1, 0, n, -1);
    // }

    // void maintainR(int p, int l, int r, int suf) {
    //     if (info[p].difr > 0 && info[p].maxlowr < suf) {
    //         return;
    //     }
    //     if (r - l == 1) {
    //         info[p].max = info[p].maxlowl;
    //         info[p].maxl = info[p].maxr = l;
    //         info[p].maxlowl = info[p].maxlowr = -inf;
    //         return;
    //     }
    //     int m = (l + r) / 2;
    //     pushDown(p);
    //     maintainR(2 * p + 1, m, r, suf);
    //     suf = max(suf, info[2 * p + 1].max);
    //     maintainR(2 * p, l, m, suf);
    //     pushUp(p);
    // }

    // void maintainR() {
    //     maintainR(1, 0, n, -1);
    // }
};

void test_1() {
    std::vector<int> init = {1, 3, 5, 7, 9, 11};
    LazySegmentTree tree(init);

    assert(tree.rangeQuery(1, 4).x == 15);

    tree.rangeApply(1, 4, {5});            // 1 8 10 12 9 11
    assert(tree.rangeQuery(1, 4).x == 30); // TODO 30

    tree.modify(2, {0}); // 1 8 0 12 9 11
    std::cout << tree.rangeQuery(2, 4).x << std::endl;
    assert(tree.rangeQuery(2, 4).x == 12);
}

void test_2() {
    int l, h, r;
    LazySegmentTree lst(1e4);
    while (std::cin >> l >> h >> r) {
        lst.rangeApply(l, r, {h});
    }
}

int main() {
    test_1();
}