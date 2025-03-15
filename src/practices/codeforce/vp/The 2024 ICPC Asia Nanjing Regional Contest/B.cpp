/*
5
0110101
01020102
0000021111
1012121010
0100202010
*/
#include <bits/stdc++.h>

const int N = 2e5 + 3;
// int a[N];

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        // int n;
        // std::cin >> n;
        std::string str;
        std::cin >> str;
        // for(int i = 1; i <= n; ++i) {
        //     std::cin >> a[i];
        // }

        int cnt = 0;
        int i = 0, j = i + 1;
        while(j < str.size()) {
            if(str[i] != str[j]) {
                i = j;
                ++j;
                cnt++;
                continue;
            }

            int tmp = 0;
            while(str[i] == str[j++] || str[j] == '2') {
                ++tmp;
            }
            if(tmp & 1) {
                cnt++;
            }
            i = j;
            j++;
        }

        std::cout << cnt << std::endl;
    }
}