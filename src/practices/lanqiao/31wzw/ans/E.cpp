#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

typedef long long i64;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    i64 sum = 0;
    for (int i = 0; i < m - 1; ++i) {
        sum += (a[i + 1] * a[i + 1] - a[i] * a[i]);
    }
    std::cout << sum << std::endl;

    return 0;
}
