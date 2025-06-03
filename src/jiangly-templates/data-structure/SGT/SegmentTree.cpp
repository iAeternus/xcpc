#include <bits/stdc++.h>

/**
 * 初始赋值+单点修改+查找前驱后继
 */
template <class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;

    SegmentTree() :
            n(0) {}

    SegmentTree(int n_, Info v_ = Info{}) {
        init(n_, v_);
    }

    template <class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }

    void init(int n_, Info v_ = Info{}) {
        init(std::vector(n_, v_));
    }

    template <class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info{});
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }

    /**
     * @brief 单点修改
     * @param p 索引
     * @param v 新值
     */
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
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }

    /**
     * @brief 区间和查询
     * @param l 区间下界（包含）
     * @param r 区间上界（不包含）
     * @return 区间和
     */
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }

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
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }

    /**
     * @brief 查找满足给定条件 pred 的第一个元素位置
     * @param l 区间下界（包含）
     * @param r 区间上界（不包含）
     * @param pred 谓词函数
     * @return 元素索引，若不存在返回 -1
     */
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
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }

    /**
     * @brief 查找满足给定条件 pred 的最后一个元素位置
     * @param l 区间下界（包含）
     * @param r 区间上界（不包含）
     * @param pred 谓词函数
     * @return 元素索引，若不存在返回 -1
     */
    template <class F>
    int findLast(int l, int r, F&& pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

void should_operate_range() {
    // Given
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    SegmentTree<int> st(nums);
    int threshold = 3;

    // When
    int idx1 = st.findFirst(0, nums.size(), [=](auto&& val) {
        return val > threshold;
    });
    int idx2 = st.findLast(0, nums.size(), [=](auto&& val) {
        return val > threshold;
    });

    // Then
    assert(idx1 == 3);
    assert(idx2 == 5);

    // When
    int res1 = st.rangeQuery(2, 4);

    // Then
    assert(res1 == 7);

    // When
    st.modify(2, 1);

    // Then
    assert(st.rangeQuery(2, 4) == 5);
}

int main() {
    should_operate_range();
}