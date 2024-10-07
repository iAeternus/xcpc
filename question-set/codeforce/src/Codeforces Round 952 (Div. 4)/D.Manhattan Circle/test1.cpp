/*
https://codeforces.com/contest/1985/problem/D
*/
#include <bits/stdc++.h>

const int N = 2e5 + 7;
std::string s[N];
int n, m;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        bool tag = false;
        int x = 1, y = 1;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> s[i];
            if (tag) {
                if (s[i][y] == '#') {
                    sum++;
                }
            } else {
                for (int j = 0; j < m; j++) {
                    if (s[i][j] == '#') {
                        sum++;
                        tag = true;
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if (sum == 0 || n == 1) {
            std::cout << x << " " << y + 1 << std::endl;
        } else {
            std::cout << x + sum / 2 << " " << y + 1 << std::endl;
        }
    }
    return 0;
}