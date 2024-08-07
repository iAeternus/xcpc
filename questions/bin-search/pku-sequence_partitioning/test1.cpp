/**
 * https://www.cnblogs.com/ruoye123456/p/17435097.html
 */
/*
Problem Description
给定n个正整数，将这个序列从左到右划分成m段，使得每段至少有一个数。

你需要让数字之和最大的那一段的数字和尽可能得小。

Input
第一行包含一个正整数
T(1≤T≤10)，表示测试数据的组数。

每组数据第一行包含两个正整数
n,m(1≤m≤n≤100000)。

第二行包含
n个正整数​ (1≤a​i≤10​^9)。

Output
对于每组数据输出一行一个整数，即你找到的方案中，数字之和最大的那一段的数字和。

输入样例1
6 4
1 5 4 6 2 3
输出样例
6
*/
#include <bits/stdc++.h>

const int N = 1e5 + 7;
int a[N];
int n, m;

/**
 * 寻找划分可行解
 */
int check(int x) {
    int res = 0, cnt = 1;
    for(int i = 1; i <= n; ++i) {
        if(res + a[i] > x) {
            ++cnt;
            res = 0;
        } else {
            res += a[i];
        }
    }
    return cnt;
}

int bin_search(int left, int right) {
    int ans = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 段数满足要求，上限缩小继续查找更小的解
        if(check(mid) <= m) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    std::cin >> n >> m;

    int max = -1, sum = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        max = std::max(max, a[i]);
        sum += a[i];
    }

    std::cout << bin_search(max, sum) << std::endl;
}