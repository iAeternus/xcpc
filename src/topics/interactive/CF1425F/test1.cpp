/**
 * @see https://www.luogu.com.cn/problem/CF1425F
 */
#include <bits/stdc++.h>

const int N = 1e3 + 5;
int n;
int a[N], pre[N];

int ask(int l, int r) {
    std::cout << "? " << l << ' ' << r << std::endl;
    std::cout.flush();
    int x;
    std::cin >> x;
    return x;
}

void ret() {
    std::cout << "! ";
    for (int i = 1; i <= n; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cin >> n;
    for (int i = n; i >= 2; --i) {
        pre[i] = ask(1, i);
    }

    for(int i = n; i >= 3; --i) {
        a[i] = pre[i] - pre[i - 1];
    }

    int x = ask(2, 3);
    a[2] = x - a[3];
    a[1] = pre[2] - a[2];

    ret();
}