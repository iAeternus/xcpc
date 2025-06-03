#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    int ave = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        ave += a[i];
    }
    ave /= n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != ave) {
            a[i + 1] -= ave - a[i];
            ++cnt;
        }
    }
    std::cout << cnt << std::endl;
}