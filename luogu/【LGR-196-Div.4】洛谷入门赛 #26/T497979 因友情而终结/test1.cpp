/**
 * https://www.luogu.com.cn/problem/B4023
 */
#include <bits/stdc++.h>

/**
 * 获取next数组
 * @par t 模式串
 * @return next数组
 */
std::vector<int> get_next(const std::string& t) {
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
std::vector<int> kmp(const std::string& s, const std::string& t) {
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
    std::string s;
    std::cin >> s;

    std::vector<int> res = kmp(s, "friend");

    int cnt = 0;
    if(res.size() == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    int i = 0;
    while(i < res.size()) {
        if(res[i + 1] - res[i] >= 9) {
            i++;
        } else {
            i += 2;
        }
        cnt++;
    }

    std::cout << cnt << std::endl;
}