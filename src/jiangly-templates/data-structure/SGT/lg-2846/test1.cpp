/**
 * @see https://www.luogu.com.cn/problem/P2846
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

struct Tag {
    int lz = 0;

    void apply(const Tag& t) {
        lz ^= 1;
    }
};

struct Info {
    int x = 0; // 亮灯数

    void apply(const Tag& t, int len) {
        x = len - x; // 区间灯数-亮灯数
    }
};

Info operator+(const Info& a, const Info& b) {
    return {a.x + b.x};
}

int main() {
    int n, m;
    std::cin >> n >> m;
    LSGT<Info, Tag> sgt(n);
    while(m--) {
        int op, s, e;
        std::cin >> op >> s >> e;
        if(op == 0) {
            sgt.rangeApply(s - 1, e, {1});
        } else {
            std::cout << sgt.query(s - 1, e).x << std::endl;
        }
    }
}