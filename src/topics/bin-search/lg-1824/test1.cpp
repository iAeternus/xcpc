/**
 * https://www.luogu.com.cn/problem/P1824
 */
#include <bits/stdc++.h>
    
const int N = 1e5 + 3;
int n, c, a[N];

/**
 * 当牛之间的距离最小为dis时，牛棚够不够
 */
bool check(int dis) {
    int cnt = 1, place = 1;
    for(int i = 2; i <= n; ++i) {
        if(a[i] - a[place] >= dis) {
            ++cnt;
            place = i;
        }
    }
    return cnt >= c;
}

/**
 * 搜索牛棚之间的最小距离的最大值
 */
int bin_search(int left, int right) {
    int ans = 0;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    std::cin >> n >> c;

    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a + 1, a + n + 1);
    std::cout << bin_search(1, a[n - 1] - a[1]) << std::endl;
}