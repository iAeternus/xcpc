#include <bits/stdc++.h>

int main() {
    int m;
    std::cin >> m;
    std::map<int, std::pair<int, int>> mp;
    int max_len = 0;
    while (m--) {
        int op, l, r, z;
        std::cin >> op;
        if (op == 1) {
            std::cin >> l >> r >> z;
            int len = r - l + 1;
            if (mp.count(z)) {
                auto [ll, rr] = mp[z];
                int old_len = rr - ll + 1;
                if (r < ll || rr < l) {
                    if (len > old_len) {
                        mp[z] = {l, r};
                        max_len = std::max()
                    }
                } else if(r == ll) {
                    mp[z] = {l, rr};
                } else if(rr == l) {
                    mp[z] = {ll, r};
                } else {
                    mp[z] = {l, r};
                }
            } else {
                mp[z] = {l, r};
            }
        } else {
            std::cin >> l >> r;
        }
    }
}