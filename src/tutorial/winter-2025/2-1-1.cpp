#include <bits/stdc++.h>

const int N = 1e5 + 3;
int a[N];

int main() {
    int n, k;
    std::cin >> n >> k;
    k--;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a, a + n);
    if (k >= std::unique(a, a + n) - a) {
        std::cout << "NO RESULT\n";
    } else {
        std::cout << a[k] << std::endl;
    }
}