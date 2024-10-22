#include <bits/stdc++.h>

const int T = 10;
const int N = 1e5 + 3;

// f[N]:可改变当前状态的方式，N为方式的种类，f[N]要在getSG之前先预处理
// SG[]:0~n的SG函数值
// S[]:为x后继状态的集合
int f[T], sg[N], s[N];

/**
 * @brief 预处理sg值，f[]、sg[]下标均从0开始，f[]需要升序排序
 * @param numF 可改变当前状态的方式的数量
 * @param n 需要处理到sg(n)
 */
void getSG(int numF, int n) {
    memset(sg, 0, sizeof(sg));
    // 因为SG[0]始终等于0，所以i从1开始
    for (int i = 1; i <= n; ++i) {
        // 每一次都要将上一状态 的 后继集合 重置
        memset(s, 0, sizeof(s));
        for (int j = 0; f[j] <= i && j < numF; ++j) {
            s[sg[i - f[j]]] = 1;  // 将后继状态的SG函数值进行标记
        }

        for (int j = 0;; ++j) {
            // 查询当前后继状态SG值中最小的非零值
            if (!s[j]) {
                sg[i] = j;
                break;
            }
        }
    }
}

int main() {
    // Given
    // 一共有n个石子
    int n = 23;

    // 一共numF种取法
    int numF = 3;
    // 每次可选择取f[i]个石子
    f[0] = 1;
    f[1] = 2;
    f[2] = 3;
    std::sort(f, f + numF);

    // When
    getSG(numF, n);

    // Then
    for(int i = 0; i <= n; ++i) {
        std::cout << "sg(" << i << ") = " << sg[i] << std::endl;
    }
}