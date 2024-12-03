/**
 * @see https://codeforces.com/contest/2042/problem/A
 */
#include <bits/stdc++.h>

void solve() {
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;
    int n, k;
    std::cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        std::cin >> a;
        pq.push(a);
        sum += a;
    }
    if(sum >= k) {
        if(pq.top() >= k) {
            std::cout << "0\n";
            return;
        } else {
            int tmp = 0, gap, min_gap = INT_MAX;
            while(!pq.empty()) {
                tmp += pq.top();
                if(tmp >= k) break;
                pq.pop();
                gap = k - tmp;
                min_gap = std::min(min_gap, gap);
            }
            std::cout << min_gap << std::endl;
        }
    } else {    
        std::cout << k - sum << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}