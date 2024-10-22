/**
 * https://www.luogu.com.cn/problem/P3397
 */
#include <bits/stdc++.h>

const int N = 5e3 + 3;
int n, m;
int diff[N][N];


void cal_diff(int x1, int y1, int x2, int y2) {
    diff[x1][y1] += 1;
    diff[x2 + 1][y1] -= 1;
    diff[x1][y2 + 1] -= 1;
    diff[x2 + 1][y2 + 1] += 1;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        cal_diff(x1, y1, x2, y2);
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            // 这里使用diff代替原数组
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            std::cout << diff[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}