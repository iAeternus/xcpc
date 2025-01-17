#include <bits/stdc++.h>

const int N = 1e3 + 5;
bool d[N][N];

void fill(std::string& str) {
    for (auto& c : str) {
        if (c == 'A' || c == 'B') {
            c = '#';
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> mp(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> mp[i];
        int cnt_a = 0, cnt_b = 0, pos_h = -1;
        for (int j = 0; j < mp[i].size(); ++j) {
            char c = mp[i][j];
            if (c == 'A') {
                ++cnt_a;
            } else if (c == 'B') {
                ++cnt_b;
            } else if (c == 'H') {
                pos_h = j;
            }
        }
        if (pos_h != -1) {
            fill(mp[i]);
            for (int j = 0; j < cnt_a; ++j) {
                mp[i][j] = 'A';
            }
            for (int j = mp[i].size() - cnt_b; j < mp[i].size(); ++j) {
                mp[i][j] = 'B';
            }
        } else {
            if (cnt_a > cnt_b) {
                fill(mp[i]);
                for (int j = mp[i].size() - cnt_a; j < mp[i].size(); ++j) {
                    mp[i][j] = 'A';
                }
            } else if (cnt_a < cnt_b) {
                fill(mp[i]);
                for (int j = 0; j < cnt_b; ++j) {
                    mp[i][j] = 'B';
                }
            } else {
                fill(mp[i]);
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         std::cout << mp[i][j];
    //     }
    //     std::cout << std::endl;
    // }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int prev = i - 1;
            int next = i + 1;
            if(mp[i][j] == 'A' || mp[i][j] == 'B') {
                if(prev >= 0 && prev < n) {
                    if(mp[i][j] == mp[prev][j]) {
                        d[i][j] = true;
                    }
                }
                if(next >= 0 && next < n) {
                    if(mp[i][j] == mp[next][j]) {
                        d[i][j] = true;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(d[i][j]) {
                mp[i][j] = '#';
            }
        }
        std::cout << mp[i] << std::endl;
    }
}