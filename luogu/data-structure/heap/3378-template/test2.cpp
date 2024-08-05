/**
 * https://www.luogu.com.cn/problem/P3378
 */
#include <bits/stdc++.h>

/*
priority_queue<int, vector<int>, less<int>>s;//less表示按照递减(从大到小)的顺序插入元素
priority_queue<int, vector<int>, greater<int>>s;//greater表示按照递增（从小到大）的顺序插入元素
*/
std::priority_queue<int, std::vector<int>, std::greater<int>> q;

int main() {
    int n;
    std::cin >> n;

    while(n--) {
        int op;
        std::cin >> op;

        if(op == 1) {
            int x;
            std::cin >> x;
            q.push(x);
        } else if(op == 2) {
            std::cout << q.top() << std::endl;
        } else {
            q.pop();
        }
    }
}