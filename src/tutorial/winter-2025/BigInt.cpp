#include <bits/stdc++.h>

constexpr int N = 1000;

struct BigInt {
    int a[N]; // 逆序存储   123 -> 3 2 1

    BigInt(int x = 0) :
            a{} {
        for(int i = 0; x; ++i) {
            a[i] = x % 10;
            x /= 10;
        }
    }

    BigInt& operator+=(int x) {
        for(int i = 0; i < N; ++i) {
            a[i] += x;
            if(a[i] >= 10) {
                a[i + 1] += 1;
                a[i] -= 10;
            }
        }
        return *this;
    }

    BigInt& operator*=(int x) {

    }

    BigInt& operator/=(int x) {

    }
};

std::ostream& operator<<(std::ostream& out, const BigInt& a) {
    int t = N - 1;
    while(a.a[t] == 0) {
        t--;
    }
    for(int i = t; i >= 0; --i) {
        out << a.a[i];
    }
    return out;
}

int main() {
    BigInt x{1234567890};
    
    x += 987654321;

    std::cout << x << std::endl;
}