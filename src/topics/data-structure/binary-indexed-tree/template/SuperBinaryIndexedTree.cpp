/**
 * 超级树状数组
 */
#include <bits/stdc++.h>

class SuperBinaryIndexedTree {
private:
    using ELEM = long long;

public:
    SuperBinaryIndexedTree(int size) :
            m_size(size) {
        m_old = 0;
        p_d1 = new ELEM[m_size + 1];
        p_d2 = new ELEM[m_size + 1];
        for (int i = 1; i <= m_size; ++i) {
            p_d1[i] = p_d2[i] = 0;
        }
    }

    SuperBinaryIndexedTree(ELEM nums[], int size) :
            SuperBinaryIndexedTree(size) {
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

void testSuperBinaryIndexedTree() {
    // Given
    int n = 10;
    ll a[] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // a[0] 不用

    SuperBinaryIndexedTree bit(n);
    for (int i = 1; i <= n; ++i) {
        bit.set(i, a[i]);
    }

    // When
    int sum1 = bit.sum(5, 8);
    bit.add(5, 100);
    int sum2 = bit.sum(5, 8);
    bit.add(5, 8, 100);
    int sum3 = bit.sum(5, 8);
    int sum4 = bit.sum(4);

    int num = bit.get(5);

    // Then
    assert(sum1 == 38);
    assert(sum2 == 138);
    assert(sum3 == 538);
    assert(sum4 == 22);
    assert(num == 208);

    for (int i = 1; i <= n; ++i) {
        std::cout << bit.get(i) << ' ';
    }
    std::cout << std::endl;
}

int main() {
    testSuperBinaryIndexedTree();
}