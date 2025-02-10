/*
小L这天获得了一个数字n，他想将其变为数字m。每一轮，小L可以从以下两种操作中任选一个进行：
1．将数字乘以2;
2．将数字开平方后下取整；
请你帮小L判断，若能进行任意轮操作（可以不进行操作），能否将数字变为m。

输入描述：
每个测试文件均包含多组测试数据。第一行输入一个整数T(1≤T≤ 105)在一行上输入两个整数n,m(0≤n,m≤109）代表初始数字、目标数字。
代表数据组数，每组测试数据描述如下：
在一行上输入两个整数n，m（0 <= n, m <= 1e9）代表初始数字、目标数字

输出描述：
对于每一组测试数据，新起一行。如果能将初始数字变为目标数字，输出 Yes，否则输出No。
示例1
输入
复制
12
01
输出
复制
Yes
No
*/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    if(n == 0 && m != 0 || n != 0 && m == 0) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}