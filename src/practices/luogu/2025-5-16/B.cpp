#include <bits/stdc++.h>

bool is_prime(int x) {
    if (x < 2) return false;
    int sqrt_x = std::sqrt(x);
    for (int i = 2; i <= sqrt_x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string s;
    std::cin >> s;
    std::map<char, int> mp;
    for (char c : s) {
        ++mp[c];
    }
    int maxn = 0, minn = INT_MAX;
    for (const auto& [c, cnt] : mp) {
        maxn = std::max(maxn, cnt);
        minn = std::min(minn, cnt);
    }

    int ans = maxn - minn;
    if (is_prime(ans)) {
        std::cout << "Lucky Word\n";
        std::cout << ans << std::endl;
    } else {
        std::cout << "No Answer\n0";
    }
}