/**
 * @see https://codeforces.com/contest/2014/problem/D
 * 下标从0开始
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, d, k;
    std::cin >> n >> d >> k;
    /*
    L[l]: 第l天的左端点个数
    R[r]: 第r天的右端点个数
    L[r]后缀和: 大于d区间的右端点r的左端点个数，也即从r天到最后一天的左端点有多少个
    R[l]前缀和: 小于d区间的左端点l的右端点个数，也即从第一天到第l天的右端点有多少个
    */
    std::vector<int> L(n + 1), R(n + 1);
    for(int i = 0; i < k; ++i) {
        int l, r;
        std::cin >> l >> r;
        L[l - 1]++;
        R[r]++;
    }
    for(int i = 1; i <= n; ++i) {
        R[i] += R[i - 1];
    }
    for(int i = n - 1; i >= 0; --i) {
        L[i] += L[i + 1];
    }

    int mx = INT_MIN;
    int imx = -1;
    int mn = INT_MAX;
    int imn = -1;

    for(int i = 0; i <= n - d; ++i) {
        // d区间外的工作数量 = 右端点小于l的区间数 + 左端点大于r的区间数
        int v = R[i] + L[i + d]; 
        if(v > mx) {
            mx = v;
            imx = i + 1;
        }
        if(v < mn) {
            mn = v;
            imn = i + 1;
        }
    }
    // 未覆盖最小值为覆盖最大值，未覆盖最大值为覆盖最小值
    std::cout << imn << ' ' << imx << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}