#include <bits/stdc++.h>

int main() {
    std::unordered_map<int, int> mp = {{1, 1}, {2, 1}, {3, 1}};
    assert(mp.size() == 3);
    for(const auto&[k, v] : mp) {
        std::cout << k << ':' << v << ' ';
    }
    std::cout << std::endl;

    // insert
    mp.insert({4, 1});
    assert(mp.size() == 4);
    mp.insert({4, 2}); // 键相同，不会插进去
    // mp: 4:1 3:1 2:1 1:1
    assert(mp.size() == 4);
    assert(mp[4] == 1);

    // []
    mp[3] = 2; // 修改
    assert(mp.size() == 4);
    assert(mp[3] == 2);

    // erase
    mp.erase(4);
    assert(mp.size() == 3);
    // mp: 3:2 2:1 1:1
    for(const auto&[k, v] : mp) {
        std::cout << k << ':' << v << ' ';
    }
    std::cout << std::endl;

    // find
    assert(mp.find(3)->second == 2);
    assert(mp.find(4) == mp.end());

    // count
    assert(mp.count(3) == 1);
    assert(mp.count(2) == 1);
    assert(mp.count(1) == 1);
    assert(mp.count(4) == 0);

    // contains since c++ 20
    assert(mp.contains(3));
    assert(mp.contains(2));
    assert(mp.contains(1));
    assert(!mp.contains(4));

    // iterator
    // 3:2 2:1 1:1
    for(auto it = mp.begin(); it != mp.end(); ++it) {
        std::cout << it->first << ':' << it->second << ' ';
    }
    std::cout << std::endl;
}