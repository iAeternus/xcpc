/**
 * @see https://www.luogu.com.cn/problem/U535982
 * 只有两种情况 ABABAB BABABA
 * 前者A在奇数位，后者B在奇数位
 * 统计原串奇数位A的数量cnt
 * 对于前者，cnt个A已经放好了，还要操作 n - cnt 次
 * 对于后者，cnt个A需要挪走，操作 cnt 次
 * 二者取最小即可，即 min(n - cnt, cnt)
 */
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt = 0;
    for(int i = 1; i <= n * 2; ++i) {
        if(i & 1 && s[i - 1] == 'A') {
            ++cnt;
        }
    }
    std::cout << std::min(n - cnt, cnt) << std::endl;
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