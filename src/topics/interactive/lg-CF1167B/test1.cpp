/**
 * @see https://www.luogu.com.cn/problem/CF1167B
 * @see https://codeforces.com/problemset/problem/1167/B
 */
#include <bits/stdc++.h>

int a[] = {-1, 4, 8, 15, 16, 23, 42};
int mul[5];

void ask(int x) {
    std::cout << "? " << x << ' ' << x + 1 << "\n";
    std::cout.flush();
    std::cin >> mul[x];
}

void ret() {
    std::cout << "! ";
    for(int i = 1; i <= 6; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << "\n";
}

bool check() {
    for(int i = 1; i <= 4; ++i) {
        if(a[i] * a[i + 1] != mul[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    for(int i = 1; i <= 4; ++i) {
        ask(i);
    }
    do {
        if(check()) {
            ret();
            break;
        }
    } while(std::next_permutation(a + 1, a + 7));
}