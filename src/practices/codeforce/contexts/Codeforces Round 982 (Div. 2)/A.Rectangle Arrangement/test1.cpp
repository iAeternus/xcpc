/**
 * @see https://codeforces.com/contest/2027/problem/0
 */
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        int w_max = 0, h_max = 0;
        for(int i = 0; i < n; ++i) {
            int w, h;
            std::cin >> w >> h;
            w_max = std::max(w_max, w);
            h_max = std::max(h_max, h);
        }

        std::cout << ((w_max + h_max) << 1) << std::endl;
    }
}