/*
样例输入 #1
5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4
样例输出 #1
11
8
20
*/
#include <bits/stdc++.h>

template <typename T>
class SegTree {
protected:
    T mergeFunc(T e1, T e2) {
        return e1 + e2;
    }

public:
#define LEFT_SON(p) ((p) << 1 | 1) // p / 2 + 1
#define RIGHT_SON(p) (((p) + 1) << 1) // p / 2 + 2
#define GET_MID(pLeft, pRight) ((pLeft) + (((pRight) - (pLeft)) >> 1)) // (pLeft + pRight) / 2

    SegTree(const std::vector<T>& nums) :
            size(nums.size()), tree(size << 2, 0), tag(size << 2) {
        build(nums, 0, 0, size - 1);
    }

    void update(int left, int right, T val) {
        update(left, right, 0, 0, size - 1, val);
    }

    T query(int left, int right) {
        return query(left, right, 0, 0, size - 1);
    }

private:
    int size;
    std::vector<T> tree;
    std::vector<T> tag;

    void pushUp(int p) {
        tree[p] = mergeFunc(tree[LEFT_SON(p)], tree[RIGHT_SON(p)]);
    }

    void addTag(int p, int pLeft, int pRight, T val) {
        tag[p] += val;
        tree[p] += val * (pRight - pLeft + 1);
    }

    void pushDown(int p, int pLeft, int pRight) {
        // 区间有lazy标记
        if (tag[p]) {
            int mid = GET_MID(pLeft, pRight);
            // 下传lazy标记到子区间
            addTag(LEFT_SON(p), pLeft, mid, tag[p]);
            addTag(RIGHT_SON(p), mid + 1, pRight, tag[p]);
            // 清除当前区间的lazy标记
            tag[p] = 0;
        }
    }

    void build(const std::vector<T>& nums, int p, int pLeft, int pRight) {
        // 初始化lazy标记为0
        tag[p] = 0;
        if (pLeft == pRight) {
            tree[p] = nums[pLeft];
            return;
        }
        int mid = GET_MID(pLeft, pRight);
        build(nums, LEFT_SON(p), pLeft, mid);
        build(nums, RIGHT_SON(p), mid + 1, pRight);
        pushUp(p);
    }

    void update(int left, int right, int p, int pLeft, int pRight, T val) {
        // 如果要修改的区间完全覆盖当前区间
        if (left <= pLeft && pRight <= right) {
            // 更新这个区间，打上lazy标记
            addTag(p, pLeft, pRight, val);
            return;
        }
        // 如果没有完全覆盖，下传lazy标记
        pushDown(p, pLeft, pRight);
        int mid = GET_MID(pLeft, pRight);
        // 修改区间与左儿子有交集，搜索左儿子
        if (left <= mid) {
            update(left, right, LEFT_SON(p), pLeft, mid, val);
        }
        // 搜索区间与右儿子有交集，搜索右儿子
        if (right > mid) {
            update(left, right, RIGHT_SON(p), mid + 1, pRight, val);
        }
        // 将当前区间的值更新
        pushUp(p);
    }

    T query(int left, int right, int p, int pLeft, int pRight) {
        // 如果要修改的区间完全覆盖当前区间
        if (left <= pLeft && pRight <= right) {
            // 直接返回当前区间的值
            return tree[p];
        }
        // 如果没有完全覆盖，下传lazy标记
        pushDown(p, pLeft, pRight);
        T res = 0;
        int mid = GET_MID(pLeft, pRight);
        // 修改区间与左儿子有交集，搜索左儿子
        if (left <= mid) {
            res = mergeFunc(res, query(left, right, LEFT_SON(p), pLeft, mid));
        }
        // 搜索区间与右儿子有交集，搜索右儿子
        if (right > mid) {
            res = mergeFunc(res, query(left, right, RIGHT_SON(p), mid + 1, pRight));
        }
        return res;
    }
};

using ll = long long;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    std::vector<ll> a;
    for (int i = 0; i < n; ++i) {
        ll tmp;
        scanf("%lld", &tmp);
        a.push_back(tmp);
    }

    SegTree<ll> t(a);

    while (m--) {
        int q, l, r;
        ll d;
        scanf("%d", &q);

        if (q == 1) {
            scanf("%d %d %lld", &l, &r, &d);
            t.update(l - 1, r - 1, d);
        } else {
            scanf("%d %d", &l, &r);
            printf("%lld\n", t.query(l - 1, r - 1));
        }
    }
}