#include <bits/stdc++.h>

char c;
std::vector<int> v;

void func(int n) {
    int w = 0, l = 0, cnt = 0;
    for (int b : v) {
        ++cnt;
        if (b) {
            ++w;
        } else {
            ++l;
        }
        if (std::max(w, l) >= n && std::abs(w - l) >= 2) {
            std::cout << w << ':' << l << std::endl;
            w = 0, l = 0, cnt = 0;
        }
    }
    std::cout << w << ':' << l << std::endl;
}

int main() {
    while (std::cin >> c, c != 'E') {
        if (c == 'W') {
            v.push_back(1);
        } else {
            v.push_back(0);
        }
    }

    func(11);
    std::cout << std::endl;
    func(21);
}