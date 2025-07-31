#include <bits/stdc++.h>

const int N = 1e7 + 3;
int n, a[N];
int max_cnt = 0, cnt = 0, idx = -1;

bool check() {
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 2) {
            flag = true;
        }

        if (flag && a[i] == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == 2) {
            ++cnt;
        } else {
            idx = i;
            max_cnt = std::max(max_cnt, cnt);
            cnt = 0;
        }
    }

    if (check()) {
        std::cout << max_cnt << std::endl;
        return 0;
    }

    int cnt2 = 0;
    for(int i = idx; i >= 0; --i) {
        if(a[i] == 2) {
            ++cnt2;
        } else {
            break;
        }
    }

    std::cout << max_cnt + cnt2 << std::endl;
}