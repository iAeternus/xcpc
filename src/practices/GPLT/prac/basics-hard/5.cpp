/**
 * @see https://pintia.cn/problem-sets/1892625959812247552/exam/problems/type/7?problemSetProblemId=1892626247629582340&page=0
 */
#include <bits/stdc++.h>

int main() {
    int x;
    std::cin >> x;
    int s = 0, n = 0;
    while (s < x) {
        s = s * 10 + 1;
        ++n;
    }
    while (true) {
        std::cout << s / x;
        s %= x;
        if (s == 0) {
            break;
        }
        s = s * 10 + 1;
        ++n;
    }
    std::cout << ' ' << n << std::endl;
}