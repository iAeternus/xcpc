#include <bits/stdc++.h>

using i64 = long long;
const int N = 25;

int dxh[] = {0, -2, -2, -1, -1, 1, 1, 2, 2};
int dyh[] = {0, -1, 1, -2, 2, -2, 2, -1, 1};

int xb, yb, xh, yh;

i64 dp[N][N];
bool mp[N][N];

int main() {
    std::cin >> xb >> yb >> xh >> yh;
    xb += 2, yb += 2, xh += 2, yh += 2;
    for (int i = 0; i <= 9; i++) {
        int nxh = xh + dxh[i];
        int nyh = yh + dyh[i];
        mp[nxh][nyh] = true;
    }

    dp[1][2] = 1;
    for (int i = 2; i <= xb; i++) {
        for (int j = 2; j <= yb; j++) {
            if (mp[i][j]) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    std::cout << dp[xb][yb] << std::endl;
}