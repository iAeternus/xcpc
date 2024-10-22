#include <bits/stdc++.h>

#define PHI 1
const int N = 1e3 + 5;

#if PHI == 1
/*
欧拉函数
O(sqrt(N))
phi(n)表示[1, N]中与N互质的数的个数

性质
1. 若a，b互质，则phi(a * b) = phi(a) * phi(b)
2. 
*/
int phi(int n) {
    int ans = n;
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            ans = ans / i * (i - 1);
            while(n % i == 0) {
                n /= i;
            }
        }
    }

    if(n > 1) {
        ans = ans / n * (n - 1);
    }

    return ans;
}

void test() {
    for(int i = 0; i <= 100; ++i) {
        std::cout << phi(i) << ' ';
    }
    std::cout << std::endl;
}

#elif PHI == 2
/*
利用埃氏筛求2-n中每个数的欧拉函数
*/
int phi[N];

void init(int n) {
    phi[1] = 1;

    for(int i = 2; i <= n; ++i) {
        phi[i] = i;
    }

    for(int i = 2; i <= n; ++i) {
        if(phi[i] == i) {
            for(int j = i; j <= n; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

void test() {
    init(100);
    for(int i = 0; i <= 100; ++i) {
        std::cout << phi[i] << ' ';
    }
    std::cout << std::endl;
}

#endif

int main() {
    test();
}