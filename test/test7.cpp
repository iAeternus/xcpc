#include <bits/stdc++.h>

std::function<int(int)> fib = [](int i) {
    if(i == 1 || i == 2) {
        return 1;
    }
    return fib(i - 1) + fib(i - 2);
};

int main() {
    int a = fib(3);
    std::cout << a << std::endl;
}