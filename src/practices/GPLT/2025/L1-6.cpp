#include <bits/stdc++.h>

std::string read(int n) {
    std::string s;
    while (n--) {
        int x;
        std::cin >> x;
        s += x + 'a' - 1;
    }
    return s;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::string s = read(n);

    while (m--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l1;
            std::cin >> l1;
            std::string b = read(l1);
            int l2;
            std::cin >> l2;
            std::string c = read(l2);

            int find = s.find(b);
            if (find != s.npos) {
                s.replace(s.begin() + find, s.begin() + find + l1, c);
            }
        } else if (op == 2) {
            std::string t;
            t += s[0];
            for (int i = 1; i < s.length(); ++i) {
                if ((s[i - 1] - 'a') + (s[i] - 'a') & 1 ^ 1) {
                    t += s[i - 1] + s[i] >> 1;
                }
                t += s[i];
            }
            s = t;
        } else {
            int l, r;
            std::cin >> l >> r;
            --l;
            std::reverse(s.begin() + l, s.begin() + r);
        }
    }

    for (int i = 0; i < s.length(); ++i) {
        std::cout << s[i] - 'a' + 1 << " \n"[i == s.length() - 1];
    }
}