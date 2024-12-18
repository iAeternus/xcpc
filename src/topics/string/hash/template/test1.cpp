#include <bits/stdc++.h>

using i64 = unsigned long long;

constexpr i64 BASE = 131;
constexpr i64 MOD1 = 212370440130137957, MOD2 = 1e9 + 7;

i64 get_hash1(const std::string& s) {
    int len = s.size();
    i64 ans = 0LL;
    for (int i = 0; i < len; ++i) {
        ans = (ans * BASE + (i64)s[i]) % MOD1;
    }
    return ans;
}

i64 get_hash2(std::string s) {
    int len = s.size();
    i64 ans = 0LL;
    for (int i = 0; i < len; i++) {
        ans = (ans * BASE + (i64)s[i]) % MOD2;
    }
    return ans;
}

/**
 * @return true=不等 false=相等
 */
bool cmp(const std::string& s, const std::string& t) {
    bool f1 = get_hash1(s) != get_hash1(t);
    bool f2 = get_hash2(s) != get_hash2(t);
    return f1 || f2;
}

int main() {
    assert(cmp("aaa", "aab") == true);
    assert(cmp("aaa", "aaa") == false);
}