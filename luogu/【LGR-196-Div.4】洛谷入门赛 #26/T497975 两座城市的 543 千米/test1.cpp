/**
 * https://www.luogu.com.cn/problem/B4020
 */
#include <bits/stdc++.h>

int main() {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;

    bool flag1 = false; // 前面有a
    bool flag2 = false; // 前面有b
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int l;
        std::cin >> l;
        for (int i = 0; i < l; ++i) {
            int c;
            std::cin >> c;

            if (c == a && !flag2) {
                flag1 = true;
            }
            if (c == b && flag1) {
                flag2 = true;
            }
        }
        if (flag1 && flag2) {
            ++cnt;
        }
        flag1 = false;
        flag2 = false;
    }
    std::cout << cnt << std::endl;
}