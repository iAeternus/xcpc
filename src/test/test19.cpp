#include <bits/stdc++.h>

const int N = 10;
int a[N][N] = {{1, 2, 3, 4, 5},
               {6, 7, 8, 9, 10},
               {11, 12, 13, 14, 15},
               {16, 17, 18, 19, 20},
               {21, 22, 23, 24, 25}};

int main() {
    int n = 5, m = 5;
    
    // 按行存储
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            assert(a[i][j] == **(a + (i * n + j) * sizeof(int)));
        }
    }

    // 按列存储
    for(int j = 0; j < m; ++j) {
        for(int i = 0; i < n; ++i) {
            assert(a[j][i] == **(a + (j * m + i) * sizeof(int)));
        }
    }
}