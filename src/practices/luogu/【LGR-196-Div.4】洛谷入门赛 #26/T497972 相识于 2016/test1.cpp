/**
 * https://www.luogu.com.cn/problem/B4017#submit
 */
#include <bits/stdc++.h>

int main() {
    int x, y;
    std::cin >> x >> y;
    if (x == 2016) {
        std::cout << y - 8 + 1;
    } else {
        if (y <= 8) {
            std::cout << (x - 2016) * 12 - (8 - y) + 1;
        } else {
            std::cout << (x - 2016) * 12 + (y - 8) + 1;
        }
    }
}