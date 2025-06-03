#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        a[x]++;
    }
    for (int i = 1; i < a.size(); ++i) {
        for (int j = 0; j < a[i]; ++j) {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
}