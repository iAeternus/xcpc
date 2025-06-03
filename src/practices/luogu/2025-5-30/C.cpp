#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::string a, b;
    std::cin >> a >> b;

    i64 cnt = 0;
    for (int i = 0; i < a.length() - 1; ++i) {
        for (int j = 1; j < b.length(); ++j) {
            if (a[i] == b[j] && a[i + 1] == b[j - 1]) {
                ++cnt;
            }
        }
    }

    std::cout << (1LL << cnt) << std::endl;
}