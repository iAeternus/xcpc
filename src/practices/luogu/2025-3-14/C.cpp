#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = i + 1;
    }
    std::sort(a.begin(), a.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    for (const auto& it : a) {
        std::cout << it.second << ' ';
    }
    std::cout << std::endl;

    double sum = 0.0;
    for (int i = 0; i < n - 1; ++i) {
        sum += a[i].first * (n - i - 1);
    }
    printf("%.2f\n", sum / n);
}