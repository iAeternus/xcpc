/*
https://codeforces.com/contest/1985/problem/A
*/
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string a, b;
        std::cin >> a >> b;
        std::swap(a[0], b[0]);
        std::cout << a << ' ' << b << std::endl;
    }
}