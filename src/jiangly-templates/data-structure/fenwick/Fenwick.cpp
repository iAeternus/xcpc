/**
 * @brief 树状数组(Fenwick)
 * @author Ricky
 * @date 2024/11/8
 * @version 1.0
 * @see https://oi-wiki.org/ds/fenwick/
 */
#include <bits/stdc++.h>

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n = 0) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        a.assign(this->n, T{});
    }

    static inline int lowbit(int x) {
        return x & -x;
    }

    /**
     * @brief 单点修改，索引从 0 开始
     * @param x 修改位置
     * @param v 增加值
     * @return void
     */
    void add(int x, const T& v) {
        for (int i = x + 1; i <= n; i += lowbit(i)) {
            a[i - 1] += v;
        }
    }

    /**
     * @brief 单点求和，索引从 0 开始
     * @param x 求和上界位置
     * @return [0, x] 区间和
     */
    T sum(int x) const {
        T ans{};
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += a[i - 1];
        }
        return ans;
    }

    /**
     * @brief 区间求和，索引从 0 开始
     * @param l 区间下界
     * @param r 区间上界
     * @return [l, r] 区间和
     */
    T rangeSum(int l, int r) const {
        return sum(r) - sum(l);
    }

    /**
     * @brief 查找累积和 <= k 的最大索引位置，索引从 1 开始
     * @param 累积和的上限值
     * @return 最大索引位置
     */
    int select(const T& k) const {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i >>= 1) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur += a[x - 1];
            }
        }
        return x;
    }

    /**
     * @brief 查询第 k 小元素，索引从 0 开始，O(log n) TODO buggy!
     * @note 注意，必须在权值数组上运行！
     */
    T kth(int k) const {
        T sum{}, x{};
        for (int i = std::__lg(n); ~i; --i) {
            x += 1 << i;
            if (x >= n || sum + a[x] >= k) {
                x -= 1 << i;
            } else {
                sum += a[x];
            }
        }
        return x + 1;
    }
};

void should_sum_range() {
    int n = 10;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Fenwick<int> f(n);
    for (int i = 0; i < n; ++i) {
        f.add(i, nums[i]);
    }

    assert(f.rangeSum(0, n) == 55);
    assert(f.select(30) == 7);
    f.add(9, -10);
    assert(f.rangeSum(0, n) == 45);
}

/**
 * @brief 区间加 [l, r]，索引从0开始
 */
template <typename T>
void rangeAdd(Fenwick<T>& f1, Fenwick<T>& f2, int l, int r, const T& v) {
    f1.add(l, v), f2.add(l, l * v);
    f1.add(r + 1, -v), f2.add(r + 1, (r + 1) * (-v));
}

/**
 * @brief 区间异或 [l, r]，索引从0开始
 */
template <typename T>
void rangeXor(Fenwick<T>& f1, Fenwick<T>& f2, int l, int r, const T& v) {
    // TODO
}

/**
 * @brief 求区间和
 */
template <typename T>
T rangeSum(Fenwick<T>& f1, Fenwick<T>& f2, int l, int r) {
    return (r + 1) * f1.sum(r) - l * f1.sum(l - 1) - f2.rangeSum(l - 1, r);
}

void should_add_range() {
    int n = 10;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 求差分数组
    std::vector<int> d;
    d.push_back(nums[0]);
    for (int i = 1; i < n; ++i) {
        d.push_back(nums[i] - nums[i - 1]);
    }

    Fenwick<int> f1(n), f2(n);
    for (int i = 0; i < n; ++i) {
        f1.add(i, d[i]);
        f2.add(i, i * d[i]);
    }

    rangeAdd(f1, f2, 3, 6, 10);
    assert(rangeSum(f1, f2, 3, 6) == 62);

    rangeAdd(f1, f2, 4, 7, -10);
    assert(rangeSum(f1, f2, 3, 6) == 32);
}

void should_find_kth() {
    int n = 5, maxNum = 4;
    std::vector<int> nums = {1, 3, 4, 3, 4};

    // 求权值数组
    std::vector<int> b(maxNum);
    for (const auto& num : nums) {
        b[num - 1]++;  // 索引从 0 开始
    }

    // 使用权值数组构造树状数组
    Fenwick<int> f(b.size());
    for (int i = 0; i < b.size(); ++i) {
        f.add(i, b[i]);
    }

    std::cout << f.kth(0) << std::endl;
    std::cout << f.kth(1) << std::endl;
    std::cout << f.kth(2) << std::endl;
    assert(f.kth(0) == 1);
    assert(f.kth(1) == 3);
    assert(f.kth(2) == 4);
}

/**
 * @brief 求逆序对数量
 */
template<typename T>
int reversePairCnt(const std::vector<T>& nums) {
    T ans{};
    Fenwick<T> f(*std::max_element(nums.begin(), nums.end()));
    for (int i = 0; i < nums.size(); ++i) {
        f.add(nums[i] - 1, 1);
        ans += i - f.sum(nums[i] - 1);
    }
    return ans;
}

void should_cal_reverse_pair_count() {
    int n = 5;
    std::vector<int> nums = {4, 2, 1, 5, 3};
    std::cout << reversePairCnt(nums) << std::endl;
    assert(reversePairCnt(nums) == 5);

    nums = {4, 3, 1, 2, 1};
    std::cout << reversePairCnt(nums) << std::endl;
    assert(reversePairCnt(nums) == 8);
}

int main() {
    should_sum_range();
    should_add_range();
    // should_find_kth();
    should_cal_reverse_pair_count();
}