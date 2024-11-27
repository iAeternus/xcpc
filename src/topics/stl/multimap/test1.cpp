#include <bits/stdc++.h>

int main() {
    std::multimap<int, int> mp = {{1, 1}, {1, 2}, {1, 3}};
    assert(mp.size() == 3);
    // 1:1 1:2 1:3
    for (const auto &[k, v] : mp) {
        std::cout << k << ':' << v << ' ';
    }
    std::cout << std::endl;

    // insert
    mp.insert({1, 4});
    assert(mp.size() == 4);
    mp.insert({2, 1});
    assert(mp.size() == 5);
    // 1:1 1:2 1:3 1:4 2:1
    for (const auto &[k, v] : mp) {
        std::cout << k << ':' << v << ' ';
    }
    std::cout << std::endl;

    // erase
    mp.erase(1);
    assert(mp.size() == 1);
    // 2:1
    for (const auto &[k, v] : mp) {
        std::cout << k << ':' << v << ' ';
    }
    std::cout << std::endl;

    mp.insert({1, 1});
    mp.insert({1, 2});
    mp.insert({1, 3});

    // count
    // 1:1 1:2 1:3 2:1
    assert(mp.count(1) == 3);
    assert(mp.count(2) == 1);

    // find
    // 寻找键等于 key 的的元素。若容器中有数个拥有所请求的键的元素，则可能返回任意一个
    std::cout << mp.find(1)->second << std::endl;

    // contains
    assert(mp.contains(1));
    assert(mp.contains(2));
    assert(!mp.contains(100));

    // 1:1 1:2 1:3 2:1
    // lower_bound 返回指向首个不小于（即大于或等于）key 的元素的迭代器。
    assert(mp.lower_bound(1)->first == 1);
    assert(mp.lower_bound(1)->second == 1);

    // upper_bound 返回指向首个大于 key 的元素的迭代器。
    assert(mp.upper_bound(1)->first == 2);
    assert(mp.upper_bound(1)->second == 1);
}