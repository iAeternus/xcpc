#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    if (n > 100) {
        std::cout << "突击小吃街 " << n - 100 << " 次\n";
    } else if (n < 100) {
        std::cout << "难道要减肥了吗？\n";
    } else {
        std::cout << "完美的平衡！\n";
    }
}