#include <bits/stdc++.h>

using i64 = long long;

bool check(int num) {
    while(num) {
        int i = num % 10;
        if(i == 2 || i == 0 || i == 1 || i == 9) {
            return true;
        }
        num /= 10;
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;
    i64 sum = 0;
    for(int i = 1; i <= n; ++i) {
        if(check(i)) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
}