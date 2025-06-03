/**
 * https://acm.hdu.edu.cn/showproblem.php?pid=1003
 * 
 * 贪心法
 */
/*
Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6
*/
#include <bits/stdc++.h>

const int INF = 0x7fffffff;

int main() {
    int t;
    std::cin >> t;

    for (int i = 1; i <= t; ++i) {
        int n;
        std::cin >> n;

        int max_sum = -INF;
        int start = 1, end = 1, p = 1; // 起点，终点，扫描位置
        int sum = 0;

        for (int j = 1; j <= n; ++j) {
            int a;
            std::cin >> a;

            sum += a;

            if (sum > max_sum) {
                max_sum = sum;
                start = p;
                end = j;
            }

            // 如果sum为负，从下一位置开始求和
            if (sum < 0) {
                sum = 0;
                p = j + 1;
            }
        }

        std::cout << "Case " << i << ':' << std::endl;
        std::cout << max_sum << ' ' << start << ' ' << end << std::endl;

        if (i != t) {
            std::cout << std::endl;
        }
    }
}
