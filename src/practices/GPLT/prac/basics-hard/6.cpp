/**
 * @see https://pintia.cn/problem-sets/1892625959812247552/exam/problems/type/7?problemSetProblemId=1892626247629582341&page=0
 */
#include <bits/stdc++.h>

void remove(std::string& s, char c) {
    int pos = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != c) {
            s[pos++] = s[i];
        }
    }
    s.resize(pos);
}

int main() {
    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);

    for (int i = 0; i < b.size(); ++i) {
        remove(a, b[i]);
    }
    std::cout << a << std::endl;
}