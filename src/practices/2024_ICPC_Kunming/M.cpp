#include <bits/stdc++.h>

const int N = 1e3 + 5;
int a[N][N];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        int num = 1, idx = 1;
        for (int k = 1; k <= m + n - 1; ++k) {
            int i = k <= m ? 1 : ++idx;
            int j = k <= m ? k : m;
            while (i <= n && j > 0) {
                a[i++][j--] = num++;
            }
        }

        std::cout << "Yes\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                std::cout << a[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
}