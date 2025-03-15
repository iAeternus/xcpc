#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        std::string s;
        std::cin >> s;
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '2') {
                ++c;
            } else if(((s[i] - '0') ^ (i & 1)) == 1) {
                ++a; // 奇0偶1
            } else {
                ++b; // 奇1偶0
            }
        }

        std::cout << std::max((int(s.size()) & 1), abs(a - b) - c) << std::endl;
    }
}