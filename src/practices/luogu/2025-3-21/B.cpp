#include <bits/stdc++.h>

int main() {
    int l, n;
    std::cin >> l >> n;
    int min_time = 0, max_time = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        min_time = std::max(min_time, std::min(x, l - x + 1));
        max_time = std::max(max_time, std::max(x, l - x + 1));
    }
    std::cout << min_time << ' ' << max_time << std::endl;
}