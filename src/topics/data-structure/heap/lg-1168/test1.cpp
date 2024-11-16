/**
 * @see https://www.luogu.com.cn/problem/P1168
 * 对顶堆：大顶堆 + 小顶堆
 * 对顶堆的定义：
 * 小顶堆存 大于小顶堆堆顶 的 所有元素
 * 大顶堆存 小于大顶堆堆顶 的 所有元素
 * 序列元素个数为奇数：小顶堆大小 == 大顶堆大小 + 1 (此时中位数为小顶堆堆顶)
 * 序列元素个数为偶数：小顶堆大小 == 大顶堆大小 (此时中位数为 (小顶堆堆顶 + 大顶堆堆顶) / 2)
 */
#include <bits/stdc++.h>

std::priority_queue<int, std::vector<int>, std::greater<int>> smallHeap;
std::priority_queue<int> bigHeap;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ans;
    for(int i = 1; i <= n; ++i) {
        int a;
        std::cin >> a;

        if(i == 1) {
            smallHeap.push(a);
        } else if(a > smallHeap.top()) {
            smallHeap.push(a);
        } else {
            bigHeap.push(a);
        }

        // 奇数，求中位数
        if(i & 1) {
            if(smallHeap.size() > bigHeap.size()) {
                while(smallHeap.size() != bigHeap.size() + 1) {
                    bigHeap.push(smallHeap.top());
                    smallHeap.pop();
                }
            } else {
                while(smallHeap.size() != bigHeap.size() + 1) {
                    smallHeap.push(bigHeap.top());
                    bigHeap.pop();
                }
            }
            ans.push_back(smallHeap.top());
        }
    }

    for(const auto& num : ans) {
        std::cout << num << std::endl;
    }
}