/**
 * @see https://codeforces.com/contest/2047/problem/C
 */
#include <bits/stdc++.h>

const int N = 5e3 + 3;
int a[3][N];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int m;
        std::cin >> m;
        for (int i = 1; i <= 2; ++i) {
            for (int j = 1; j <= m; ++j) {
                std::cin >> a[i][j];
            }
        }
        if(m == 1) {
            std::cout << a[1][1] + a[2][1] << std::endl;
            continue;
        }

        int max_sum = 0, max_sum_j = -1;
        for (int j = 1; j <= m; ++j) {
            if (a[1][j] + a[2][j] > max_sum) {
                max_sum = a[1][j] + a[2][j];
                max_sum_j = j;
            }
        }

        int ls = 0, rs = 0;
        for(int j = 1; j <= m; ++j) {
            if(j == max_sum_j) continue;
            if(a[1][j] > a[2][j]) {
                ls += a[1][j];
            } else {
                rs += a[2][j];
            }
        }
        std::cout << ls + max_sum + rs << std::endl;
    }
}