#include <bits/stdc++.h>

const int N = 1e3 + 5;
using ELEM = long long;

/**
 * 超级树状数组
 */
class SuperBinaryIndexedTree {
public:
    SuperBinaryIndexedTree(ELEM nums[], int size)
        : n(size) {
        for (int i = 1; i <= n; ++i) {
            add(d1, i, nums[i] - nums[i - 1]);
            add(d2, i, (i - 1) * (nums[i] - nums[i - 1]));
        }
    }

    /**
     * 区间修改 [left, right] + val
     */
    void add(int left, int right, ELEM val) {
        if (left <= right) {
            add(d1, left, val);
            add(d1, right + 1, -val);
            add(d2, left, val * (left - 1));
            add(d2, right + 1, -val * right);
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
    int sum(int left, int right) {
        if (left > right) {
            return 0;
        }
        return right * sum(d1, right) - sum(d2, right) - (left - 1) * sum(d1, left - 1) + sum(d2, left - 1);
    }

    /**
     * 单点查询前缀和 [1, idx]
     */
    int sum(int idx) {
        return sum(1, idx);
    }

    /**
     * 获取原数组元素 nums[idx]
     */
    int get(int idx) {
        return sum(idx, idx);
    }

private:
    int n;
    ELEM d1[N] = {0}, d2[N] = {0};

    int lowbit(int x) {
        return x & (-x);
    }

    void add(ELEM diff[], int idx, ELEM val) {
        for (int i = idx; i <= n; i += lowbit(i)) {
            diff[i] += val;
        }
    }

    int sum(ELEM diff[], int idx) {
        int res = 0;
        for (int i = idx; i; i -= lowbit(i)) {
            res += diff[i];
        }
        return res;
    }
};

void testSuperBinaryIndexedTree() {
    // Given
    int n = 10;
    ELEM a[] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};  // a[0] 不用
    SuperBinaryIndexedTree bit(a, n);

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

    for(int i = 1; i <= n; ++i) {
        std::cout << bit.get(i) << ' ';
    }
    std::cout << std::endl;
}

int main() {
    testSuperBinaryIndexedTree();
}