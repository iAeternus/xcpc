#include <bits/stdc++.h>

/**
 * r[i]表示以t中第i个字符为中心的最长回文半径（包括自身）
 * 求出来的max(r[i] - 1)即为最长回文子串的长度
 */
std::vector<int> manacher(const std::string& s) {
    std::string t = "#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    std::vector<int> r(n);
    for (int i = 0, j = 0; i < n; ++i) {
        if (2 * j - i >= 0 && j + r[j] > i) {
            r[i] = std::min(r[2 * j - i], j + r[j] - i);
        }
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i] += 1;
        }
        if (i + r[i] > j + r[j]) {
            j = i;
        }
    }
    return r;
}

int main() {
    std::string s;
    std::cin >> s;
    auto r = manacher(s);
    int ans = 0;
    for (auto it : r) {
        ans = std::max(ans, it);
    }
    std::cout << ans - 1 << std::endl;
}