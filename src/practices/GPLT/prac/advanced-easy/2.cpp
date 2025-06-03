#include <bits/stdc++.h>

int main() {
    std::string s;
    std::getline(std::cin, s);
    int max_size = 0;
    for (int i = 0; i < s.length(); ++i) {
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            --l, ++r;
        }
        max_size = std::max(max_size, r - l - 1);

        l = i, r = i + 1;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            --l, ++r;
        }
        max_size = std::max(max_size, r - l - 1);
    }
    std::cout << max_size << std::endl;
}