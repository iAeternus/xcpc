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

void print(int m, int k) {
    for (int i = 1; i <= m; ++i) {
        if (i != 1) std::cout << '+';
        std::cout << i << '^' << k;
    }
}

int main() {
    int n;
    std::cin >> n;
    bool ok = false;
    for(int k = 32; k >= 1; --k) {
        i64 sum = 0;
        if(ok) break;
        for(int m = 1; ; ++m) {
            sum += qpow(m, k);
            if(sum > n) {
                break;
            }
            if(sum == n) {
                ok = true;
                print(m, k);
                break;
            }
        }
    }

    if(!ok) {
        std::cout << "Impossible for " << n << ".";
    }
}