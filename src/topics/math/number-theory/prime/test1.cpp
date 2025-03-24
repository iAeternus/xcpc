#include <bits/stdc++.h>

bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }
    int sqrt_n = sqrt(n);
    for(int i = 2; i <= sqrt_n; ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 100;
    for(int i = 0; i < n; ++i) {
        if(isPrime(i)) {
            std::cout << i << ' ';
        }
    }
}