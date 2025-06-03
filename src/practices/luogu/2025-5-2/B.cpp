#include <bits/stdc++.h>

std::string s;

bool f() {
    for (char c : s) {
        if (c != 'Z') {
            return false;
        }
    }
    return true;
}

int main() {
    std::cin >> s;

    if (f()) {
        for (int i = 0; i < s.length(); ++i) {
            std::cout << '0';
        }
        std::cout << std::endl;
        for (int i = 0; i < s.length(); ++i) {
            std::cout << '0';
        }
        std::cout << std::endl;
        return 0;
    }

    int idx = s.find('Z');
    if (idx != s.npos) {
        for (int i = idx; i < s.length(); ++i) {
            if (s[i] != 'Z') {
                std::cout << -1 << std::endl;
                return 0;
            }
        }
    }

    std::string x, y;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == 'X') {
            x += '1';
            y += '0';
        } else if (c == 'Y') {
            x += '0';
            y += '1';
        } else if (c == 'Z') {
            x += '1';
            y += '1';
        }
    }
    std::cout << x << "\n"
              << y << "\n";
}