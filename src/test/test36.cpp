#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> m(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> m[i][j];
        }
    }

    std::vector<std::vector<int>> col_pre(n, std::vector<int>(n + 1, 0));
    for (int c = 0; c < n; ++c) {
        for (int r = 0; r < n; ++r) {
            col_pre[c][r + 1] = col_pre[c][r] + m[r][c];
        }
    }

    int max_sum = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            std::vector<int> tmp(n);
            for (int c = 0; c < n; ++c) {
                tmp[c] = col_pre[c][j + 1] - col_pre[c][i];
            }
            // 最大子数组和
            int cur_max = tmp[0];
            int max_ = cur_max;
            for(int k = 1; k < n; ++k) {
                cur_max = std::max(tmp[k], cur_max + tmp[k]);
                max_ = std::max(max_, cur_max);
            }

            max_sum = std::max(max_sum, max_);
        }
    }

    std::cout << max_sum << std::endl;
}
