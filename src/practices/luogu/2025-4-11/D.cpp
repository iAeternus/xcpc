#include <bits/stdc++.h>

int main() {
    int a, b;
    std::cin >> a >> b;
    int t = int(log2(b - a + 1)) + 1;
    std::cout << t << ' ' << t * 100 << std::endl;
}