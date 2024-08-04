/*
https://codeforces.com/contest/1986/problem/B
*/
#include <bits/stdc++.h>

const int N = 105;
int a[N][N];
int n, m;

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool isMax(int x, int y) {
    int cur = a[x][y], m1, m2, m3, m4;
    if (isValid(x - 1, y)) {
        m1 = a[x - 1][y];
        if (m1 > cur) return false;
    }
    if (isValid(x, y - 1)) {
        m2 = a[x][y - 1];
        if (m2 > cur) return false;
    }
    if (isValid(x + 1, y)) {
        m3 = a[x + 1][y];
        if (m3 > cur) return false;
    }
    if (isValid(x, y + 1)) {
        m4 = a[x][y + 1];
        if (m4 > cur) return false;
    }
    return true;
}

int getMax(int x, int y) {
    int cur = a[x][y], arr[4] = {0};
    if (isValid(x - 1, y)) {
        arr[0] = a[x - 1][y];
    }
    if (isValid(x, y - 1)) {
        arr[1] = a[x][y - 1];
    }
    if (isValid(x + 1, y)) {
        arr[2] = a[x + 1][y];
    }
    if (isValid(x, y + 1)) {
        arr[3] = a[x][y + 1];
    }
    std::sort(arr, arr + 4);
    return arr[3] > cur ? cur : arr[3];
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> a[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isMax(i, j)) {
                    int tmp = getMax(i, j);
                    a[i][j] = tmp;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << a[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
}