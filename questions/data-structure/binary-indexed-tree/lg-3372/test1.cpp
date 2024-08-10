/**
 * https://www.luogu.com.cn/problem/P3372
 */
#include <bits/stdc++.h>

class SuperBinaryIndexedTree {
private:
    using ELEM = long long;
public:
    SuperBinaryIndexedTree(int size) : m_size(size) {
        m_old = 0;
        p_d1 = new ELEM[m_size + 1];
        p_d2 = new ELEM[m_size + 1];
        for(int i = 1; i <= m_size; ++i) {
            p_d1[i] = p_d2[i] = 0;
        }
    }

    SuperBinaryIndexedTree(ELEM nums[], int size)
        : SuperBinaryIndexedTree(size) {
        for (int i = 1; i <= m_size; ++i) {
            add(p_d1, i, nums[i] - nums[i - 1]);
            add(p_d2, i, (i - 1) * (nums[i] - nums[i - 1]));
        }
    }

    ~SuperBinaryIndexedTree() {
        delete[] p_d1;
        delete[] p_d2;
        p_d1 = nullptr;
        p_d2 = nullptr;
    }

    /**
     * 设置元素 nums[idx] = num
     */
    void set(int idx, ELEM num) {
        add(p_d1, idx, num - m_old);
        add(p_d2, idx, (idx - 1) * (num - m_old));
        m_old = num;
    }

    /**
     * 区间修改 [left, right] + val
     */
    void add(int left, int right, ELEM val) {
        if (left <= right) {
            add(p_d1, left, val);
            add(p_d1, right + 1, -val);
            add(p_d2, left, val * (left - 1));
            add(p_d2, right + 1, -val * right);
        }
    }

    /**
     * 单点修改 nums[idx] += val
     */
    void add(int idx, ELEM val) {
        add(idx, idx, val);
    }

    /**
     * 区间查询前缀和 [left, right]
     */
    ELEM sum(int left, int right) {
        if (left > right) {
            return 0;
        }
        return right * sum(p_d1, right) - sum(p_d2, right) - (left - 1) * sum(p_d1, left - 1) + sum(p_d2, left - 1);
    }

    /**
     * 单点查询前缀和 [1, idx]
     */
    ELEM sum(int idx) {
        return sum(1, idx);
    }

    /**
     * 获取原数组元素 nums[idx]
     */
    ELEM get(int idx) {
        return sum(idx, idx);
    }

private:
    int m_size;
    ELEM m_old; // 前一个录入的值
    ELEM* p_d1;
    ELEM* p_d2;

    int lowbit(int x) {
        return x & (-x);
    }

    void add(ELEM diff[], int idx, ELEM val) {
        for (int i = idx; i <= m_size; i += lowbit(i)) {
            diff[i] += val;
        }
    }

    ELEM sum(ELEM diff[], int idx) {
        ELEM res = 0;
        for (int i = idx; i; i -= lowbit(i)) {
            res += diff[i];
        }
        return res;
    }
};

using ll = long long;
int n, m;

int main() {
    // freopen("P3372_8.in", "r", stdin);

    scanf("%d %d", &n, &m);
    SuperBinaryIndexedTree bit(n);
    for(int i = 1; i <= n; ++i) {
        ll a;
        scanf("%lld", &a);
        bit.set(i, a);
    }

    while(m--) {
        int op;
        scanf("%d", &op);

        int x, y;
        ll k;
        if(op == 1) {
            scanf("%d %d %lld", &x, &y, &k);
            bit.add(x, y, k);
        } else if (op == 2) {
            scanf("%d %d", &x, &y);
            std::cout << bit.sum(x, y) << std::endl;
        }
    }
}