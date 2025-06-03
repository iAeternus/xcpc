#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    std::stringstream ss;
    char last;
    for (char c : s) {
        if (isalpha(c)) {
            last = c;
            ss << c;
        } else {
            int cnt = c - '1';
            for (int i = 0; i < cnt; ++i) {
                ss << last;
            }
        }
    }
    std::cout << ss.str() << std::endl;
}