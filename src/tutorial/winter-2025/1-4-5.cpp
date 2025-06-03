#include <bits/stdc++.h>

int main() {
    std::vector<int> a = {1, 2, 3};

    for (auto it = a.begin(); it != a.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    for (const auto& num : a) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    a.push_back(4);

    for (const auto& num : a) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    a.pop_back();

    for (const auto& num : a) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    a.clear();

    assert(a.size() == 0);
}