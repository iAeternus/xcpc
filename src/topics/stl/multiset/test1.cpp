#include <bits/stdc++.h>

int main() {
    std::multiset<int> ms = {1, 2, 2, 3, 3};
    assert(ms.size() == 5);
    for (const auto& it : ms) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    // insert
    ms.insert(2);
    assert(ms.size() == 6);
    for (const auto& it : ms) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    // merge since c++ 17
    std::multiset<int> ms2 = {2, 2, 3, 3, 4};
    ms.merge(ms2);
    assert(ms.size() == 11);
    for (const auto& it : ms) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    // count
    // ms: 1 2 2 2 2 2 3 3 3 3 4
    assert(ms.count(2) == 5);
    assert(ms.count(3) == 4);

    // find
    assert(ms.find(1) == ms.begin());
    assert(ms.find(100) == ms.end());

    // contains since c++ 20
    assert(ms.contains(1));
    assert(ms.contains(2));
    assert(ms.contains(3));
    assert(ms.contains(4));
    assert(!ms.contains(100));

    // ==
    // ms: 1 2 2 2 2 2 3 3 3 3 4
    std::multiset<int> ms3 = {1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4};
    assert(ms == ms3);

    // erase
    ms.erase(2);
    assert(ms.size() == 6);
    // ms: 1 3 3 3 3 4
    for (const auto& it : ms) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    ms.erase(std::next(ms.begin()));
    assert(ms.size() == 5);
    // ms: 1 3 3 3 4
    for (const auto& it : ms) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;
}