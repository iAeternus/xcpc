/*
小明正在进行一个解谜，解密的条件和方式具体如下：
在一条直线上摆放着n个骰子，以垂直于直线的俯视视角看去，骰子有四个面是垂直于视角的，每个骰子的四个面都按顺时针分别有编号1、2、3、4，只考虑这四个面，初始骰子的摆放都是两面平行于直线，两面垂直于直线，但编号1的初始朝向位置是随机的。（规定，垂直于直线的俯视视角，以上方向为起点，顺时针一次编号朝向为1、2、3、4；骰子从左到右依次编号1、2、3......n）
现在我们需要完成操作：选择一个骰子，使骰子顺时针旋转90°，同时，相邻的骰子会进行相同的操作，进行若干次操作后，使所有骰子的相同编号朝向一致，操作次数不作限制。

输入说明：
第一行给出一个正整数t，表示要解谜的次数
后2t行的每2行，首行给出一个正整数n，表示骰子的数量，二行给出n个正整数，表示编号1的初始朝向
输入保证，初始时，朝向不一致

输出说明：
对于每次解谜，若可解，则在一行内按照操作顺序给出操作的骰子的编号（多解输出一种即可），若无解，则一行内输出0

输入样例：
2
2
1 3
3
1 3 1

输出样例：
0
1 1 3 3

样例说明：
对于解谜一，两个骰子，初始朝向不一致，无论如何操作，后续都不会一致，无解，输出0
对于解谜二，操作骰子1两次后，
编号1朝向为3 1 1，再操作骰子3两次后，
编号1朝向为3 3 3，所有朝向一致，符合题意，按照操作顺序输出1 1 3 3
*/
#include <bits/stdc++.h>

using namespace std;

// 扩展欧几里得算法求逆元
int extended_gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = extended_gcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_gcd(a, m, x, y);
    if (g != 1) return -1; // 逆元不存在
    return (x % m + m) % m;
}

// 构造系数矩阵A
vector<vector<int>> construct_matrix(int n) {
    vector<vector<int>> A(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        if (i > 0) A[i][i - 1] = 1;
        A[i][i] = 1;
        if (i < n - 1) A[i][i + 1] = 1;
    }
    return A;
}

// 高斯消元法解线性方程组Ax ≡ b mod m
vector<int> solve_mod_system(vector<vector<int>> A, vector<int> b, int m) {
    int n = A.size();
    vector<vector<int>> mat(n, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = A[i][j] % m;
        }
        mat[i][n] = b[i] % m;
        if (mat[i][n] < 0) mat[i][n] += m;
    }

    for (int col = 0; col < n; ++col) {
        // 寻找主元
        int pivot = -1;
        for (int row = col; row < n; ++row) {
            if (mat[row][col] != 0) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;

        swap(mat[col], mat[pivot]);

        int val = mat[col][col];
        int inv = mod_inverse(val, m);
        if (inv == -1) return {};

        // 归一化主元行
        for (int j = col; j <= n; ++j) {
            mat[col][j] = (mat[col][j] * inv) % m;
            if (mat[col][j] < 0) mat[col][j] += m;
        }

        // 消去其他行
        for (int row = 0; row < n; ++row) {
            if (row != col && mat[row][col] != 0) {
                int factor = mat[row][col];
                for (int j = col; j <= n; ++j) {
                    mat[row][j] = (mat[row][j] - factor * mat[col][j]) % m;
                    if (mat[row][j] < 0) mat[row][j] += m;
                }
            }
        }
    }

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        x[i] = mat[i][n] % m;
        for (int j = 0; j < n; ++j) {
            if (j != i && mat[i][j] != 0) {
                return {};
            }
        }
        if (mat[i][i] == 0 && x[i] != 0) return {};
    }

    return x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= 4;
    }

    for (int t = 0; t < 4; ++t) {
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            d[i] = (t - a[i]) % 4;
            if (d[i] < 0) d[i] += 4;
        }

        vector<vector<int>> A = construct_matrix(n);
        vector<int> x = solve_mod_system(A, d, 4);

        if (!x.empty()) {
            // 验证解是否正确
            bool valid = true;
            for (int i = 0; i < n; ++i) {
                int ci = 0;
                if (i > 0) ci += x[i - 1];
                ci += x[i];
                if (i < n - 1) ci += x[i + 1];
                ci %= 4;
                if ((a[i] + ci) % 4 != t) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                vector<int> ops;
                for (int i = 0; i < n; ++i) {
                    for (int k = 0; k < x[i]; ++k) {
                        ops.push_back(i + 1);
                    }
                }
                for (size_t k = 0; k < ops.size(); ++k) {
                    cout << ops[k] << (k == ops.size() - 1 ? "\n" : " ");
                }
                return;
            }
        }
    }

    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
