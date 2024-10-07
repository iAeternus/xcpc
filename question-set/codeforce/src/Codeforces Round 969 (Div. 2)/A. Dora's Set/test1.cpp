/**
 * @see https://codeforces.com/contest/2007/problem/0
 */
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int l, r;
        std::cin >> l >> r;

        int cnt = 0;
        for(int i = l; i <= r; ++i) {
            if(i & 1) {
                ++cnt;
            }
        }

        std::cout << cnt / 2 << std::endl;
    }
}