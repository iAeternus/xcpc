#include <bits/stdc++.h>

const int N = 1e5 + 7;
int a[N];

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        for(int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += a[i];
        }
        std::cout << sum << std::endl;
    }
}