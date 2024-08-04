/*
https://codeforces.com/contest/1986/problem/A
*/
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int max_ = std::max(std::max(a, b), c);
        int min_ = std::min(std::min(a, b), c);
        std::cout << max_ - min_ << std::endl;
    }
}