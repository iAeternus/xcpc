#include <bits/stdc++.h>

void print(int n, char ch) {
    for(int i = n; i >= 1; --i) {
        int cnt = 2 * i - 1;
        for(int j = 0; j < n - i; ++j) {
            std::cout << ' ';
        }
        for(int j = 0; j < cnt; ++j) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }

    for(int i = 2; i <= n; ++i) {
        int cnt = 2 * i - 1;
        for(int j = 0; j < n - i; ++j) {
            std::cout << ' ';
        }
        for(int j = 0; j < cnt; ++j) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    char ch;
    std::cin >> n >> ch;

    int l = 0;
    while(2 * l * l - 1 <= n) {
        ++l;
    }
    l--;

    print(l, ch);
    std::cout << n - (2 * l * l - 1) << std::endl;
}