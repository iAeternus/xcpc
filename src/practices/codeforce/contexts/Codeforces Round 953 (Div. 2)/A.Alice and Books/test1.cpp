/*
https://codeforces.com/contest/1978/problem/0
*/
#include <bits/stdc++.h>

const int N = 105;
int a[N];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }

        int last = a[n];

        std::sort(a + 1, a + n);
        int last1 = a[n - 1];

        std::cout << last + last1 << std::endl;
    }
}