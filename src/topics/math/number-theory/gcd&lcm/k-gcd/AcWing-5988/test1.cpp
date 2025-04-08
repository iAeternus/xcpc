/**
 * @see https://www.acwing.com/problem/content/5991/
 */
#include <bits/stdc++.h>

const int N = 1e5 + 3;
std::vector<int> s[N];

int main() {
    int n;
    std::cin >> n;

    int ma = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        ma = std::max(ma, a[i]);
    }
    std::sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        int sq = std::sqrt(a[i]);
        for (int j = 1; j <= sq; ++j) {
            if (a[i] % j == 0) {
                s[j].push_back(a[i]);
                if (a[i] / j != j) {
                    s[a[i] / j].push_back(a[i]);
                }
            }
        }
    }

    for (int i = ma; i >= 1; --i) {
        if (s[i].size() >= 3) {
            for (int j = 0; j < 3; ++j) {
                std::cout << s[i][j] << ' ';
            }
            std::cout << std::endl;
            break;
        }
    }
}