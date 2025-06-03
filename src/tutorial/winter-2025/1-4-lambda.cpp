#include <bits/stdc++.h>

int main() {
    int n = 9;
    int a[] = {6, 5, 7, 4, 8, 3, 9, 2, 1};
    std::vector<int> v = {6, 5, 7, 4, 8, 3, 9, 2, 1};

    std::sort(a, a + n, [](int& a, int& b) {
        return a > b;
    });
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    std::sort(v.begin(), v.end(), [](int& a, int& b) {
        return a > b;
    });
    for (const auto& it : v) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
}