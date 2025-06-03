#include <bits/stdc++.h>

int main() {
    std::array<int, 10> arr;
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    for (const auto& num : arr) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    std::cout << arr.front() << std::endl;
    std::cout << arr.back() << std::endl;
}