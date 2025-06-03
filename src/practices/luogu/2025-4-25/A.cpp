#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        a[i] = -x;
    }

    int cur_max = a[0];
    int max_ = a[0];
    for (int i = 1; i < n; ++i) {
        cur_max = std::max(a[i], cur_max + a[i]);
        max_ = std::max(max_, cur_max);
    }

    std::cout << max_ + 1 << std::endl;
}