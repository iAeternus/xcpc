/**
 * https://www.luogu.com.cn/problem/B4018
 */
#include <bits/stdc++.h>

int main() {
    int a1, b1, c1, a2, b2, c2;
    std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if(a1 < a2) {
        std::cout << 'B';
    } else if(a1 > a2) {
        std::cout << 'A';
    } else {
        if(b1 < b2) {
            std::cout << "B";
        } else if(b1 > b2) {
            std::cout << "A";
        } else {
            if(c1 < c2) {
                std::cout << "A";
            } else {
                std::cout << "B";
            }
        }
    }
}