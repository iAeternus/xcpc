/**
 * @see https://codeforces.com/contest/2025/problem/B
 */
#include <bits/stdc++.h>

const int N = 1e5 + 3;
const int MOD = 1e9 + 7;
int n[N], k[N];

void solve(std::vector<std::vector<int>>& C, int max_n) {
    for(int n = 0; n < max_n; ++n) {
        C[n][0] = 1;
        C[n][n] = 1;
        for(int k = 1; k < n; ++k) {
            C[n][k] = (C[n][k - 1] + C[n - 1][k - 1]) % MOD;
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    int max_n = -1;
    
    for(int i = 0; i < t; ++i) {
        std::cin >> n[i];
        max_n = std::max(max_n, n[i]);
    }

    for(int i = 0; i < t; ++i) {
        std::cin >> k[i];
    }

    std::vector<std::vector<int>> C(max_n, std::vector<int>(max_n, 0));

    solve(C, max_n);

    for(int i = 0; i < t; ++i) {
        std::cout << C[n[i]][k[i]] << std::endl;
    }
}