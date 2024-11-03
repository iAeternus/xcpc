#include <bits/stdc++.h>

// std::function<int(int)> fib = [](int i) {
//     if(i == 1 || i == 2) {
//         return 1;
//     }
//     return fib(i - 1) + fib(i - 2);
// };

int main() {
    auto fib = [](this auto&& self, int n, int i = 0, int num1 = 0, int num2 = 1) -> int {
        return i >= n ? num1 : self(n, i + 1, num2, num1 + num2);
    };

    int a = fib(3);
    std::cout << a << std::endl;
}