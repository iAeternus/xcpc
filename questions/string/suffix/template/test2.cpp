#include <bits/stdc++.h>

const int N = 2e5 + 5; // 字符串的长度

int sa[N], rk[N], tmp[N + 1];
int k, n;

/**
 * 组合数有两部分
 * 高位是rk[i]，低位是rk[i + k]
 */
auto comp_sa = [&](int i, int j) -> bool {
    if(rk[i] != rk[j]) {
        return rk[i] < rk[j];
    } else {
        int ri = i + k <= n ? rk[i + k] : -1;
        int rj = j + k <= n ? rk[j + k] : -1;
        return ri < rj;
    }
};

/**
 * 计算s的后缀数组
 * O(n log n)
 * @par s 文本串
 * @par sa 后缀数组，需要开足够的栈空间
 */
void calc_sa(const std::string& s, int* sa) {
    n = s.length();
    for(int i = 0; i <= n; ++i) {
        rk[i] = s[i];
        sa[i] = i;
    }
    for(k = 1; k <= n; k <<= 1) {
        std::sort(sa, sa + n, comp_sa);
        tmp[sa[0]] = 0;
        for(int i = 0; i < n; ++i) {
            tmp[sa[i + 1]] = tmp[sa[i]] + (comp_sa(sa[i], sa[i + 1]) ? 1 : 0);
        }
        for(int i = 0; i < n; ++i) {
            rk[i] = tmp[i];
        }
    }
}

int main() {
    std::string s;
    std::cin >> s;

    calc_sa(s, sa);

    for(int i = 0; i < s.length(); ++i) {
        std::cout << sa[i] << ' ';
    }
}