/*
Problem Description

N个气球排成一排，从左到右依次编号为1,2,3…N.每次给定2个整数a b(a <= b),
lele便为骑上他的“小飞鸽"牌电动车从气球a开始到气球b依次给每个气球涂一次颜色。
但是N次以后lele已经忘记了第I个气球已经涂过几次颜色了，你能帮他算出每个气球被涂过几次颜色吗？

Input
每个测试实例第一行为一个整数N,(N <= 100000).接下来的N行，每行包括2个整数a b(1 <= a <= b <= N)。
当N = 0，输入结束。

Output
每个测试实例输出一行，包括N个整数，第I个数代表第I个气球总共被涂色的次数。

Sample Input
3
1 1
2 2
3 3
3
1 1
1 2
1 3
0

Sample Output
1 1 1
3 2 1
*/
#include <bits/stdc++.h>

const int N = 1e6 + 3;
int nums[N], diff[N];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        memset(nums, 0, sizeof nums);
        memset(diff, 0, sizeof diff);
        for (int i = 1; i <= n; ++i) {
            int l, r;
            scanf("%d %d", &l, &r);
            // 区间修改
            diff[l]++;
            diff[r + 1]--;
        }

        // 求原数组
        for (int i = 1; i <= n; ++i) {
            nums[i] = nums[i - 1] + diff[i]; // 对差分求前缀和就是原数组
            if (i != n) {
                printf("%d ", nums[i]);
            } else {
                printf("%d\n", nums[i]);
            }
        }
    }
}