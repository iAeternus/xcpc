#include <bits/stdc++.h>

const int N = 1e6 + 3;
int n, a[N];

bool check(int x) {
    for(int i = 1; i <= n; ++i) {
        x += a[i];
        if(x <= 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cin >> n;
    for(int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    int l = 1, r = 1000000000;
    while(l < r) {
        int mid = l + ((r - l) >> 1);
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << std::endl;
}