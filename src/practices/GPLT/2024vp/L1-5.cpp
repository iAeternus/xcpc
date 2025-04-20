/*
5
MaoNiang
SeQing
BaoLi
WeiGui
BuHeShi
4
BianCheng MaoNiang ba! WeiGui De Hua Ye Keyi Shuo! BuYao BaoLi NeiRong.


2
AB
BB
3
AAABBB


*/
#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> a;
    for (int i = 0; i < n; ++i) {
        std::string x;
        std::cin >> x;
        a.push_back(x);
    }
    int k;
    std::string s;
    std::cin >> k;
    std::cin.get();
    std::getline(std::cin, s);
    int cnt = 0;
    std::vector<std::pair<int, int>> v;
    for (const auto& w : a) {
        int idx = 0;
        while (idx < s.length()) {
            auto it = s.find(w, idx);
            if (it == std::string::npos) {
                break;
            }
            ++cnt;
            v.push_back({it, w.length()});
            idx += w.length();
        }
    }
    if (cnt < k) {
        for (const auto& [pos, len] : v) {
            s.replace(pos, len, "<censored>");
        }
        std::cout << s << std::endl;
    } else {
        std::cout << cnt << std::endl;
        std::cout << "He Xie Ni Quan Jia!\n";
    }
}