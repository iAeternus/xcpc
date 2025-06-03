#include <bits/stdc++.h>

const int N = 5e5 + 7;

/**
 * 树状数组
 */
class BinaryIndexedTree {
public:
    int size;
    int tree[N] = {0};

    BinaryIndexedTree(int n) :
            size(n) {}

    BinaryIndexedTree(int nums[], int n) :
            size(n) {
        for (int i = 1; i <= this->size; ++i) {
            add(i, nums[i]);
        }
    }

    int lowbit(int x) {
        return x & (-x);
    }

    /**
     * 单点修改，修改元素 tree[i] += val
     */
    void add(int i, int val) {
        while (i <= size) {
            tree[i] += val;
            i += lowbit(i);
        }
    }

    /**
     * 区间修改 [l, r] 整体+val
     * 注意，调用此函数后只能调用sum(i)来获取原数组a[i]
     */
    void add(int l, int r, int val) {
        if (l < r) {
            add(l, val);
            add(r, -val);
        }
    }

    /**
     * 查询前缀和
     * @return 返回前缀和sum = a[1] + a[2] + ... + a[i]
     */
    int sum(int i) {
        int ans = 0;
        while (i > 0) {
            ans += tree[i];
            i -= lowbit(i);
        }
        return ans;
    }

    /**
     * 查询区间和 [i, j]
     */
    int sum(int i, int j) {
        return sum(j) - sum(i - 1);
    }
};

void testBinaryIndexedTree1() {
    // Given
    int n = 10;
    int a[] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // a[0] 不用
    BinaryIndexedTree bit(a, n);

    // When
    int sum1 = bit.sum(5, 8);
    bit.add(5, 100);
    int sum2 = bit.sum(5, 8);
    bit.add(5, -100);
    int sum3 = bit.sum(5, 8);

    // Then
    assert(sum1 == 38);
    assert(sum2 == 138);
    assert(sum3 == 38);
}

void testBinaryIndexedTree2() {
    // Given
    int n = 10;
    BinaryIndexedTree bit(n);
    int l = 5, r = 8;

    // When
    bit.add(l, r, -10);

    // Then
    for (int i = 1; i <= n; ++i) {
        std::cout << bit.sum(i) << ' ';
    }
    std::cout << std::endl;
}

int main() {
    testBinaryIndexedTree1();
    testBinaryIndexedTree2();
}