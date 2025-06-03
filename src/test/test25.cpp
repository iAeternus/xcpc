/**
 * @see https://codeforces.com/problemset/problem/2038/L
 */
#include <bits/stdc++.h>

// true=够 false=不够
bool check(int mid) {
}

int main() {
    int n;
    std::cin >> n;
    int l = 1, r = 100000;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << r << std::endl;
}