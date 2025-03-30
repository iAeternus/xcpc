/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=1754
 */
/*
Sample Input
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5

Sample Output
5
6
5
9
*/

/**
 * 树状数组（Fenwick Tree/BIT）实现区间最值
 * - 核心思想：利用二进制索引特性，每个节点存储特定区间的统计值
 * - 适用场景：单点更新 + 区间查询（最值/求和）
 * - 时间复杂度：O(n log n) 建树，O(log n) 更新/查询
 * 
 * 模板说明：
 * 1. 修改合并方式：将 std::max 改为其他操作（如加法、最小值）
 * 2. 修改数据存储：a[] 存储原始数据，tree[] 存储区间统计值
 * 3. 注意最值操作的局限性：无法高效处理区间覆盖更新
 */
#include <bits/stdc++.h>

const int N = 2e5 + 10;
/**
 * 初始化 memset(tree, 0, sizeof tree);
 */
int n, m, a[N], tree[N];

int lowbit(int x) {
    return x & -x;
}

/**
 * 单点更新：更新所有包含x的区间
 * 初始化建树时 update(i, a[i]);
 */
void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tree[x] = val;
        for (int i = 1; i < lowbit(x); i <<= 1) {
            tree[x] = std::max(tree[x], tree[x - i]);
        }
    }
}

/**
 * 区间查询：从右往左合并区间
 */
int query(int l, int r) {
    int ans = 0;
    while (r >= l) {
        ans = std::max(ans, a[r]); // 先比较原始数据
        --r;                       // 移动到下一个待处理位置
        // 如果剩余区间可以跳跃到前一个块
        while (r - lowbit(r) >= l) {
            ans = std::max(ans, tree[r]);
            r -= lowbit(r);
        }
    }
    return ans;
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
        memset(tree, 0, sizeof tree);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            update(i, a[i]);
        }

        while (m--) {
            char s[5];
            int A, B;
            scanf("%s %d %d", &s, &A, &B);
            if (s[0] == 'Q') {
                printf("%d\n", query(A, B));
            } else {
                a[A] = B;
                update(A, B);
            }
        }
    }
}