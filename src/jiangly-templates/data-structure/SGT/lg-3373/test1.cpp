/**
 * @see https://www.luogu.com.cn/problem/P3373
 */
#include <bits/stdc++.h>

template <class Info, class Tag>
struct LSGT {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    LSGT() {}

    LSGT(int n_, Info v_ = Info{}) {
        init(n_, v_);
    }

    template <class T>
    LSGT(std::vector<T> init_) {
        init(init_);
    }

    void init(int n_, Info v_ = Info{}) {
        init(std::vector(n_, v_));
    }

    inline int left(int p) {
        return p << 1;
    }

    inline int right(int p) {
        return p << 1 | 1;
    }

    template <class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info{});
        tag.assign(4 << std::__lg(n), Tag{});
        auto build = [&](auto self, int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = l + r >> 1;
            self(self, left(p), l, m);
            self(self, right(p), m, r);
            pushUp(p);
        };
        build(build, 1, 0, n);
    }

    void pushUp(int p) {
        info[p] = info[left(p)] + info[right(p)];
    }

    void apply(int p, const Tag& v, int len) {
        info[p].apply(v, len);
        tag[p].apply(v);
    }

    void pushDown(int p, int len) {
        apply(left(p), tag[p], len >> 1);
        apply(right(p), tag[p], len - (len >> 1));
        tag[p] = Tag{};
    }

    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = l + r >> 1;
        pushDown(p, r - l);
        if (x < m) {
            modify(left(p), l, m, x, v);
        } else {
            modify(right(p), m, r, x, v);
        }
        pushUp(p);
    }

    /**
     * @brief 单点修改
     */
    void modify(int p, const Info& v) {
        modify(1, 0, n, p, v);
    }

    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info{};
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = l + r >> 1;
        pushDown(p, r - l);
        return query(left(p), l, m, x, y) + query(right(p), m, r, x, y);
    }

    /**
     * @brief 区间查询
     */
    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v, r - l);
            return;
        }
        int m = l + r >> 1;
        pushDown(p, r - l);
        rangeApply(left(p), l, m, x, y, v);
        rangeApply(right(p), m, r, x, y, v);
        pushUp(p);
    }

    /**
     * @brief 区间操作
     */
    void rangeApply(int l, int r, const Tag& v) {
        return rangeApply(1, 0, n, l, r, v);
    }
};

using ll = long long;
int n, q, m;

struct Tag {
    ll mul, add;

    Tag(ll mul = 1, ll add = 0)
        : mul(mul), add(add) {}  // 乘法默认 1，加默认 0

    void apply(Tag t) {
        mul = 1LL * mul * t.mul % m;
        add = (1LL * add * t.mul + t.add) % m;
    }
};

struct Info {
    ll sum = 0LL;

    void apply(const Tag& t, int len) {
        sum = (1LL * sum * t.mul + 1LL * t.add * len) % m;
    }
};

Info operator+(const Info& a, const Info& b) {
    return {(a.sum + b.sum) % m};
}

int main() {
    std::cin >> n >> q >> m;
    std::vector<Info> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].sum;
    }
    LSGT<Info, Tag> sgt(a);
    while (q--) {
        int op, x, y;
        ll k;
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y >> k;
            sgt.rangeApply(x - 1, y, Tag(k, 0));
        } else if (op == 2) {
            std::cin >> x >> y >> k;
            sgt.rangeApply(x - 1, y, Tag(1, k));
        } else {
            std::cin >> x >> y;
            std::cout << sgt.query(x - 1, y).sum << std::endl;
        }
    }
}