#include <bits/stdc++.h>

int main() {
    int n = 6;
    int a[] = {3, 4, 4, 2, 5, 1};
    std::vector<int> a2 = {3, 4, 4, 2, 5, 1};

    std::sort(a, a + n);
    std::sort(a2.begin(), a2.end());

    int n2 = std::unique(a, a + n) - a;
    int n3 = std::unique(a2.begin(), a2.end()) - a2.begin();

    std::cout << n2 << ' ' << n3 << std::endl;
}