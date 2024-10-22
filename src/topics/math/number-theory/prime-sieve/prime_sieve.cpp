#include <bits/stdc++.h>

#define IS_PRIME 3
const int N = 1e3 + 5;

#if IS_PRIME == 1
/*
朴素算法
O(N)
试除法
*/
bool is_prime(int num) {
    if(num == 1) {
        return false;
    }

    int tmp = sqrt(num);
    for(int i = 2; i <= tmp; ++i) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

void test() {
    for(int i = 1; i <= 100; ++i) {
        if(is_prime(i)) {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
}

#elif IS_PRIME == 2
/*
埃氏筛法
O(N log log N)
给定素数x，筛掉2x、3x...
*/
bool check[N];
int primes[N], cnt;

bool is_prime(int num) {
    return !check[num];
}

void get_primes(int n) {
    for(int i = 2; i <= n; ++i) {
        if(is_prime(i)) {
            primes[++cnt] = i;
            for(int j = i; j * i <= n; ++j) {
                check[j * i] = true;
            }
        }
    }
}

void test() {
    get_primes(100);

    for(int i = 1; i <= cnt; ++i) {
        std::cout << primes[i] << ' ';
    }
    std::cout << std::endl;
}

#elif IS_PRIME == 3
/*
欧拉筛
O(N)
存在合数在埃氏筛中重复标记
对于[2, n]的每个整数i，将小于他的所有质数与他相乘得到的合数进行标记，保证每个合数只被标记一次
*/
bool check[N];
int primes[N], cnt;

bool is_prime(int num) {
    return !check[num];
}

void get_primes(int n) {
    for(int i = 2; i <= n; ++i) {
        if(is_prime(i)) {
            primes[++cnt] = i;
        }

        for(int j = 1; j <= cnt && i * primes[j] <= n; ++j) {
            check[i * primes[j]] = true;
            if(i % primes[j] == 0) {
                break;
            }
        }
    }
}

void test() {
    get_primes(100);

    for(int i = 1; i <= cnt; ++i) {
        std::cout << primes[i] << ' ';
    }
    std::cout << std::endl;
}

#endif

int main() {
    test();
}