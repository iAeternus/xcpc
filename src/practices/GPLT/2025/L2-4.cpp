#include <bits/stdc++.h>

using i64 = long long;

i64 qpow(i64 a, i64 n) {
    i64 ans = 1;
    while (n) {
        if (n & 1) {
            ans *= a;
        }
        a *= a;
        n >>= 1;
    }
    return ans;
}

int main() {
    int n;
    i64 a, b;
    std::cin >> n >> a >> b;
    std::vector<bool> v(b - a + 1);
    for(int i = 2; i <= n; ++i) {
        i64 mask = qpow(10, n - i);
        for(int j = a; j <= b; ++j) {
            if(v[j - a]) continue;
            v[j - a] = (j / mask) % i;
        }
    }
    int cnt = 0;
    for(int i = a; i <= b; ++i) {
        if(!v[i - a]) {
            ++cnt;
            std::cout << i << std::endl;
        }
    }
    if(cnt == 0) {
        std::cout << "No Solution" << std::endl;
    }
}