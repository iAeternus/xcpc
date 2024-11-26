#include <bits/stdc++.h>

void lShift(const std::string::iterator& begin, const std::string::iterator& end, const std::string::iterator& k) {
    std::reverse(begin, k);
    std::reverse(k, end);
    std::reverse(begin, end);
}

int count(const std::string& s, const std::string& ss) {
    int cnt = 0;
    int pos = s.find(ss);

    // 找第一个子串
    if (pos != -1) {
        cnt++;
    } else {
        return cnt;
    }

    // 找后续子串
    while (pos != -1) {
        pos = s.find(ss, pos + 1);
        if (pos != -1) {
            cnt++;
        } else {
            return cnt;
        }
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::string a;
        std::cin >> n >> k >> a;
        auto it = a.find("nanjing");
        if (it == std::string::npos) {
            std::cout << 0 << std::endl;
            continue;
        }

        lShift(a.begin(), a.end(), a.begin() + std::min(k, int(it)));

        std::cout << count(a, "nanjing") << std::endl;
    }
}