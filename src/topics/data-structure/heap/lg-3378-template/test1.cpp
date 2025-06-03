/**
 * https://www.luogu.com.cn/problem/P3378
 */
#include <bits/stdc++.h>

const int N = 1e6 + 5;

/// @brief 小根堆
int heap[N], len = 0; // len：当前二叉树的长度

#define LEFT_CHILD(i) ((i) << 1) // 左儿子
#define RIGHT_CHILD(i) (((i) << 1) + 1) // 右儿子
#define PARENT(i) ((i) >> 1) // 父节点

/**
 * 插入元素
 */
void push(int x) {
    heap[++len] = x;
    int i = len;
    while (i > 1 && heap[i] < heap[PARENT(i)]) {
        std::swap(heap[i], heap[PARENT(i)]);
        i = PARENT(i);
    }
}

/**
 * 弹出元素
 */
void pop() {
    heap[1] = heap[len--];
    int i = 1;
    while (LEFT_CHILD(i) <= len) {
        int left_son = LEFT_CHILD(i); // 左儿子
        // left_son < len 表示有右儿子，选二子中较小的
        if (left_son < len && heap[RIGHT_CHILD(i)] < heap[left_son]) {
            ++left_son;
        }

        if (heap[left_son] < heap[i]) {
            std::swap(heap[left_son], heap[i]);
            i = left_son; // 下沉到儿子处
        } else {
            // 如果不比儿子小，就停止下沉
            break;
        }
    }
}

/**
 * 获取堆头
 */
int top() {
    return heap[1];
}

/**
 * 获取长度
 */
int size() {
    return len;
}

/**
 * 判空
 */
bool empty() {
    return 0 == len;
}

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int x;
            std::cin >> x;
            push(x);
        } else if (op == 2) {
            std::cout << top() << std::endl;
        } else {
            pop();
        }
    }
}