/**
 * @see https://www.luogu.com.cn/problem/P3375
 */
#include <bits/stdc++.h>

/**
 * 获取next数组
 * @par t 模式串
 * @return next数组
 */
std::vector<int> get_next(std::string t) {
    int m = t.size();
    std::vector<int> next(m, 0);
    int j = 0;  // j为模式串中已匹配的前缀长度
    for (int i = 1; i < m; ++i) {
        while (j > 0 && t[i] != t[j]) {
            j = next[j - 1];
        }
        if (t[i] == t[j]) {
            ++j;
        }
        next[i] = j;
    }
    return next;
}

/**
 * tmp算法匹配模式串
 * @par s 文本串
 * @par t 模式串
 * @return t在s中出现的所有位置（起始索引），若不存在，则返回空列表
 */
std::vector<int> kmp(std::string s, std::string t) {
    std::vector<int> res;
    std::vector<int> next = get_next(t);
    int n = s.size(), m = t.size();
    int j = 0;  // j为模式串中已匹配的前缀长度
    for (int i = 0; i < n; ++i) {
        while (j > 0 && s[i] != t[j]) {
            j = next[j - 1];
        }
        if (s[i] == t[j]) {
            ++j;
        }
        // 模式串匹配完
        if (j == m) {
            res.push_back(i - m + 1);
            j = next[j - 1];
        }
    }
    return res;
}

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::vector<int> res = kmp(s1, s2);
    for (const auto& i : res) {
        std::cout << i + 1 << std::endl;
    }

    std::vector<int> next = get_next(s2);
    for (int i = 0; i < s2.size(); ++i) {
        std::cout << next[i] << ' ';
    }
}