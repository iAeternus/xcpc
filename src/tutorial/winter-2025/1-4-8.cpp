#include <bits/stdc++.h>

struct cmp {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

int main() {
    std::priority_queue<int> pq;

    pq.push(2);
    pq.push(3);

    while (!pq.empty()) {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }

    std::priority_queue<int, std::vector<int>, std::greater<>> pq2;

    pq2.push(2);
    pq2.push(3);

    while (!pq2.empty()) {
        std::cout << pq2.top() << std::endl;
        pq2.pop();
    }
}