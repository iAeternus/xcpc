#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

typedef long long i64;
#define PI 3.1415926535

int main() {
    int n;
    std::cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x >= 3) {
            ++cnt;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
