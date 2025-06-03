/**
 * @see http://poj.org/problem?id=1011
 */
#include <bits/stdc++.h>
#include <algorithm>

const int N = 70;
int a[N];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + 1 + n, [](const int& a, const int& b) {
        return a > b;
    });
    // TODO
}