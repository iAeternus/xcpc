#include <bits/stdc++.h>

int main() {
    std::string s;
    bool tag = false;
    int cnt = 0;
    while (std::getline(std::cin, s)) {
        auto pos = s.find(' ');
        auto user = s.substr(0, pos);
        auto msg = s.substr(pos + 1);

        if (user == "小A" && msg == "能带吗") {
            if (tag) {
                tag = false;
            } else {
                ++cnt;
            }
            continue;
        }

        if (msg.find("吃") != std::string::npos) {
            tag = true;
        }
    }
    cnt += tag;
    std::cout << cnt << std::endl;
}