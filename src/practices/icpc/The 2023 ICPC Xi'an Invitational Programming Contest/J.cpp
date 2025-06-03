#include <bits/stdc++.h>

bool eq(double a, double b) {
    return fabs(a - b) < 1e-4;
}

std::string f2s(double x) {
    std::string ans;
    for (int b = 0; b < 14; ++b) {
        x *= 2;
        if (x >= 1) {
            ans += '1';
            x -= 1;
        } else {
            ans += '0';
        }
    }
    return ans;
}

int main() {
    double a, b;
    std::cin >> a >> b;
    auto bb = f2s(b);
    std::string ans = "1111111111111";
    for (int i = bb.length() - 1; i >= 0; --i) {
        if (bb[i] == '0') {
            ans += '1';
        } else {
            ans += '2';
        }
    }
    std::cout << ans << std::endl;
}