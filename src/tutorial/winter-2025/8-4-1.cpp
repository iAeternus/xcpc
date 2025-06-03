#include <bits/stdc++.h>

const int N = 203;
int a[N], prefix[N], dp_min[N][N], dp_max[N][N];

int sum(int i, int j) {
    return prefix[j + 1] - prefix[i];
}

int main() {
    int n;
    std::cin >> n;
    int n2 = n << 1;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[n + i] = a[i];
    }
    prefix[0] = a[0];
    for (int i = 1; i <= n2; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < n2; ++j) {
            dp_min[i][j] = i == j ? 0 : INT_MAX;
        }
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n2 - len; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                dp_min[i][j] = std::min(dp_min[i][j], dp_min[i][k] + dp_min[k + 1][j] + sum(i, j));
                dp_max[i][j] = std::max(dp_max[i][j], dp_max[i][k] + dp_max[k + 1][j] + sum(i, j));
            }
        }
    }

    int min_ans = INT_MAX, max_ans = 0;
    for (int i = 0; i < n; ++i) {
        min_ans = std::min(min_ans, dp_min[i][i + n - 1]);
        max_ans = std::max(max_ans, dp_max[i][i + n - 1]);
    }
    std::cout << min_ans << std::endl;
    std::cout << max_ans << std::endl;
}