/**
 * https://www.luogu.com.cn/problem/B4019
 */
#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        sum1 += a;
    }

    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        sum2 += a;
    }

    int score = ceil((sum1 + sum2) / 2.0);

    std::cout << score;
}