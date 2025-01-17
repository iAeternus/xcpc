#include <bits/stdc++.h>

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    int sqrtNum = sqrt(num);
    for (int i = 2; i <= sqrtNum; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(isPrime(1) == false);
    assert(isPrime(2) == true);
    assert(isPrime(3) == true);
    assert(isPrime(4) == false);
}