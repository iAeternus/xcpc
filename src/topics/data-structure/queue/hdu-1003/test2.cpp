/**
 * https://acm.hdu.edu.cn/showproblem.php?pid=1003
 * 
 * dp
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
/*
dp[i]: 以 a[i] 结尾的最大子序和
dp[i] = max(
    dp[i - 1] + a[i],
    a[i]
)
*/
#include <bits/stdc++.h>

const int N = 1e5 + 3;
int dp[N], a[N];

// int main() {
//     int t;
//     std::cin >> t;

//     for(int k = 1; k <= t; ++k) {
//         int n;
//         std::cin >> n;

//         for(int i = 1; i <= n; ++i) {
//             std::cin >> a[i];
//         }

//         int start = 1, end = 1, p = 1;
//         dp[1] = a[1];
//         int max_sum = a[1];

//         for(int i = 2; i <= n; ++i) {
//             if(dp[i - 1] + a[i] >= dp[i]) {
//                 dp[i] = dp[i - 1] + a[i];
//             } else {
//                 dp[i] = a[i];
//                 p = i;
//             }

//             if(dp[i] > max_sum) {
//                 max_sum = dp[i];
//                 start = p;
//                 end = i;
//             }
//         }

//         std::cout << "Case " << k << ':' << std::endl;
//         std::cout << max_sum << ' ' << start << ' ' << end << std::endl;

//         if(k != t) {
//             std::cout << std::endl;
//         }
//     }
// }

int main() {
    int t;
    std::cin >> t;

    for (int k = 1; k <= t; ++k) {
        int n;
        std::cin >> n;

        for (int i = 1; i <= n; ++i) {
            std::cin >> dp[i];
        }

        int start = 1, end = 1, p = 1;
        int max_sum = dp[1];

        for (int i = 2; i <= n; ++i) {
            if (dp[i - 1] + dp[i] >= dp[i]) {
                dp[i] = dp[i - 1] + dp[i];
            } else {
                p = i;
            }

            if (dp[i] > max_sum) {
                max_sum = dp[i];
                start = p;
                end = i;
            }
        }

        std::cout << "Case " << k << ':' << std::endl;
        std::cout << max_sum << ' ' << start << ' ' << end << std::endl;

        if (k != t) {
            std::cout << std::endl;
        }
    }
}