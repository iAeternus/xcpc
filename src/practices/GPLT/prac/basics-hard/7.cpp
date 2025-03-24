/**
 * @see https://pintia.cn/problem-sets/1892625959812247552/exam/problems/type/7?problemSetProblemId=1892626247629582342&page=0
 */
#include <bits/stdc++.h>

int min4(int& a, int& b, int& c, int& d) {
    int res = std::min(a, std::min(b, std::min(c, d)));
    a -= res;
    b -= res;
    c -= res;
    d -= res;
    return res;
}

int main() {
    std::string s;
    std::cin >> s;
    int hash[27] = {0};
    for(int i = 0; i < s.size(); ++i) {
        s[i] = toupper(s[i]);
        ++hash[s[i] - 'A'];
    }
    int cnt_g = hash['G' - 'A'];
    int cnt_p = hash['P' - 'A'];
    int cnt_l = hash['L' - 'A'];
    int cnt_t = hash['T' - 'A'];
    int cnt = min4(cnt_g, cnt_p, cnt_l, cnt_t);
    while(cnt--) {
        std::cout << "GPLT";
    }
    while(cnt_g || cnt_p || cnt_l || cnt_t) {
        if(cnt_g) {
            std::cout << "G";
            cnt_g--;
        }
        if(cnt_p) {
            std::cout << "P";
            cnt_p--;
        }
        if(cnt_l) {
            std::cout << "L";
            cnt_l--;
        }
        if(cnt_t) {
            std::cout << "T";
            cnt_t--;
        }
    }
}