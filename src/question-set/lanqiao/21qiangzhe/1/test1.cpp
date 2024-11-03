/**
 * @see https://www.lanqiao.cn/problems/19977/learning/?contest_id=216
 */
#include <bits/stdc++.h>

using ll = long long;
ll a[100003];

int main() {
    int n;
    std::cin >> n;
    ll max_num = 0L, sum = 0L;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
        max_num = std::max(a[i], max_num);
    }
    if (sum - max_num <= 0) {
        std::cout << sum << std::endl;
    } else {
        std::cout << (sum - max_num) * 2 + (max_num - sum + max_num) * 2 - 1 << std::endl;
    }
}