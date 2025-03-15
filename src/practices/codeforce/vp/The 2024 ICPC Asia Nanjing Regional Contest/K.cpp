#include <bits/stdc++.h>

const int N = 1e5 + 3;
int red[N], black[N];

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n, m, k, w;
        std::cin >> n >> m >> k >> w;
        for(int i = 0; i < n; ++i) {
            std::cin >> red[i];
        }

        for(int i = 0; i < m; ++i) {
            std::cin >> black[i];
        }
        black[m] = w + 1;

        std::sort(black, black + m + 1);

        int idx = 0;
        std::vector<int> ans;
        for(int i = 0; i <= m; ++i) {
            int size = -1;
            if(i == 0) {
                size = black[i] - 1;
            } else {
                size = black[i] - black[i - 1] - 1;
            }
            std::vector<bool> vec(size, false);

            // std::cout << vec.size() << std::endl;
            
            for(int j = 0; j < size; ++j) {
                if(red[idx + j]) {
                    vec[j] = true;

                    if(black[idx + j + k]) {
                        
                    }
                    ans.push_back(idx + j);
                }
            }



            idx += (black[i] + 1);
        }
    }
}