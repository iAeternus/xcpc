#include <bits/stdc++.h>

/**
 * 在s中查找t
 * 时间复杂度 O(m log n)
 * @par s 文本串
 * @par t 模式串
 * @par sa 后缀数组
 * @return 返回t在s中的位置 
 */
int find(const std::string& s, const std::string& t, int* sa) {
    int i = 0, j = s.length();
    while (j - i > 1) {
        int k = i + ((j - i) >> 1);
        if (s.compare(sa[k], t.length(), t) < 0) {
            i = k;
        } else {
            j = k;
        }
    }

    if (s.compare(sa[j], t.length(), t) == 0) {
        return sa[j];
    }
    if (s.compare(sa[i], t.length(), t) == 0) {
        return sa[i];
    }
    return -1; // 没找到
}

int main() {
    std::string s = "vamamadn", t = "ad";
    int sa[] = {5, 3, 1, 6, 4, 2, 7, 0}; // 后缀数组
    int pos = find(s, t, sa);
    std::cout << pos << std::endl;
}