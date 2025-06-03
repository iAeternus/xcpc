/**
 * 取子问题
 * 
 */
#include <bits/stdc++.h>

const int N = 1e3 + 5;
int t, n, a[N];

char status[N]; // 'P'=必败点 'N'=必胜点

void solve() {
    status[0] = 'P'; // 终结点为P
    int cnt;
    for (int i = 0; i <= n; ++i) {
        cnt = 0;
        for (int j = 0; j < t; ++j) {
            if (status[i - a[j]] == 'P') {
                status[i] = 'N'; // 一步到P => N
            } else {
                cnt++;
            }
        }
        if (cnt == t) {
            status[i] = 'P'; // 一步只能到N => P
        }
    }
}

int main() {
    std::cin >> n >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> a[i];
    }

    solve();

    for (int i = 0; i <= n; ++i) {
        std::cout << i << ' ' << status[i] << std::endl;
    }
}