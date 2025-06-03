#include <bits/stdc++.h>

using i64 = long long;
const int MOD = 1e9 + 7;

i64 mod_pow(i64 a, i64 b, i64 mod = MOD) {
    i64 ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    i64 n;
    std::cin >> n;
    std::cout << mod_pow(2, n >> 1) << std::endl;
}