#include <bits/stdc++.h>

struct C {
    int a, b, g, k;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<C> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i].a >> v[i].b >> v[i].g >> v[i].k;
    }
    int x, y;
    std::cin >> x >> y;
    for (int i = n - 1; i >= 0; --i) {
        int a = v[i].a, b = v[i].b;
        int xx = a + v[i].g;
        int yy = b + v[i].k;
        if (x >= a && x <= xx && y >= b && y <= yy) {
            std::cout << i + 1 << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
}