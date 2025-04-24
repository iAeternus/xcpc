#include <bits/stdc++.h>

const int N = 1e2 + 3;
int a[N][N], b[N][N], c[N][N];

int main() {
    int n, m, k; // [n, m] * [m, k]
    std::cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            std::cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; i++) { // 遍历a每一行
        for (int j = 0; j < k; j++) { // 遍历b每一列
            for (int kk = 0; kk < m; kk++) { // 相乘再相加
                c[i][j] += a[i][kk] * b[kk][j];
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < k; ++j) {
            std::cout << c[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}