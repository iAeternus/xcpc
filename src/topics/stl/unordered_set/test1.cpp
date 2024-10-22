#include <bits/stdc++.h>

/**
 * 遍历 since c++ 11
 * 可以看出 unordered_set 是无序，不重复的
 */
template <class Os, class K>
Os& operator<<(Os& os, const std::unordered_set<K>& v) {
    os << '[' << v.size() << "] {";
    bool o{};
    for (const auto& e : v) {
        os << (o ? ", " : (o = 1, " ")) << e;
    }
    return os << " }";
}

int main() {
    // 底层实现 hash table
    std::unordered_set<int> us = {2, 7, 1, 8, 2, 8};
    std::cout << us << std::endl;  // [4] { 8, 1, 7, 2 }

    // 插入元素，若重复则不做任何事 O(1)
    // 如果操作后新的元素数量大于原 max_load_factor() * bucket_count() 则会发生重散列。
    // 如果（因插入而）发生了重散列，索引迭代器均会失效。否则（未发生重散列），则迭代器不会失效。
    us.insert(9);
    std::cout << us << std::endl;  // [5] { 9, 8, 1, 7, 2 }

    // 移除元素 O(1)
    us.erase(us.begin());             // 移除开头
    us.erase(std::next(us.begin()));  // 移除第二个元素
    std::cout << us << std::endl;     // [3] { 8, 7, 2 }

    us.erase(7);                   // 移除具体值
    std::cout << us << std::endl;  // [2] { 8, 2 }

    // iterator erase( const_iterator first, const_iterator last );

    // merge 合并两个集合 O(N)
    std::unordered_set<char>
        p{'C', 'B', 'B', 'A'},
        q{'E', 'D', 'E', 'C'};

    p.merge(q);
    std::cout << "p: " << p << std::endl;  // p: [5] { E, D, A, B, C }
    std::cout << "q: " << q << std::endl;  // q: [1] { C }

    // count 只要set中存在这个元素，count就返回1，否则返回0
    std::unordered_set set{2, 7, 1, 8, 2, 8, 1, 8, 2, 8};
    std::cout << set << std::endl;  // [4] { 8, 1, 7, 2 }

    const auto [min, max] = std::ranges::minmax(set);  // since c++ 20
    for (int i = min; i <= max; ++i) {
        if (set.count(i) == 1) {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;

    // find 查找指定元素
    // 找得到返回迭代器，找不到返回 end()
    if (auto res = set.find(2); res != set.end()) {
        std::cout << "Find: " << *res << std::endl;
    } else {
        std::cout << "Not found!" << std::endl;
    }

    // contains 判断集合中是否存在该元素 since c++ 20
    for (int x : {2, 5}) {
        if (set.contains(x)) {
            std::cout << "Find: " << x << std::endl;  // Find: 2
        } else {
            std::cout << "Not found: " << x << std::endl;  // Not found: 5
        }
    }

    // clear 清空集合
    set.clear();
    std::cout << set << std::endl;  // [0] { }
}