/*
sample input
5
4000 201 11 45 11

sample output
5 4 1 3 1
*/
#include <bits/stdc++.h>

struct data {
    int val; // 值
    int id; // 位置

    // bool operator<(const data& other) {
    //     return this->val < other.val;
    // }
};

const int N = 5e5 + 10;
data old_nums[N]; // 离散化之前的数据
int new_nums[N]; // 离散化之后的数据

int main() {
    int n;
    std::cin >> n;
    
    for(int i = 1; i <= n; ++i) {
        // 读入元素的值
        std::cin >> old_nums[i].val;
        // 记录元素的位置
        old_nums[i].id = i;
    }

    std::sort(old_nums + 1, old_nums + n + 1, [](const data& o1, const data& o2) {
        if(o1.val == o2.val) {
            return o1.id < o2.id;
        }
        return o1.val < o2.val;
    });

    for(int i = 1; i <= n; ++i) {
        // 这个元素原来的位置在old_nums[i].id，把他的值赋为i
        new_nums[old_nums[i].id] = i;
        
        // 若两个元素的原值相同，把新值也赋为相同
        if(old_nums[i].val == old_nums[i - 1].val) {
            new_nums[old_nums[i].id] = new_nums[old_nums[i - 1].id];
        }
    }

    for(int i = 1; i <= n; ++i) {
        std::cout << new_nums[i] << ' ';
    }
}