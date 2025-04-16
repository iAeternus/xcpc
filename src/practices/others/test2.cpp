/*
小明正在进行一个解谜，解密的条件和方式具体如下：
在一条直线上摆放着n个骰子，以垂直于直线的俯视视角看去，骰子有四个面是垂直于视角的，每个骰子的四个面都按顺时针分别有编号1、2、3、4，只考虑这四个面，初始骰子的摆放都是两面平行于直线，两面垂直于直线，但编号1的初始朝向位置是随机的。（规定，垂直于直线的俯视视角，以上方向为起点，顺时针一次编号朝向为1、2、3、4；骰子从左到右依次编号1、2、3......n；每个骰子有一个或两个相关骰子，相关骰子可能包括自身）
现在我们需要完成操作：选择一个骰子，使骰子顺时针旋转90°，随后，相关的骰子会进行相同的操作，进行若干次操作后，使所有骰子的相同编号朝向一致，操作次数不作限制。

输入说明：
第一行给出一个正整数t，表示要解谜的次数
每次解谜给出n+2行，首行给出一个整数n，表示骰子数量，二行给出n个正整数，表示编号1的初始朝向
后n行，每行给出两个整数，每个整数表示第i个骰子的相关骰子的编号（编号0用于占位，便于输入）

输出说明：
对于每次解谜，若可解，则在一行内按照操作顺序给出操作的骰子的编号（多解输出一种即可），若无解，则一行内输出0

输入样例：
2
2
1 3
0 1
0 2
3
1 3 1
2 0
1 3
0 2

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
using Matrix = vector<vector<int>>;

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
    return (g == 1) ? (x % m + m) % m : -1;
}

Matrix construct_matrix(int n, const vector<vector<int>>& relations) {
    Matrix A(n, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) {
        A[j][j] = (A[j][j] + 1) % 4;
        for (int k : relations[j]) {
            if (k >= 1 && k <= n) {
                A[k - 1][j] = (A[k - 1][j] + 1) % 4;
            }
        }
    }
    return A;
}

vector<int> gauss_mod4(Matrix a, vector<int> b) {
    const int MOD = 4;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        // 寻找主元
        int pivot = -1;
        for (int row = i; row < n; ++row) {
            if (a[row][i] % MOD != 0) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;

        swap(a[i], a[pivot]);
        swap(b[i], b[pivot]);

        // 处理主元
        int val = a[i][i];
        int inv = mod_inverse(val, MOD);
        if (inv == -1) {                  // 处理不可逆情况
            if (b[i] % 2 != 0) return {}; // 无解
            inv = 1;                      // 当val=2时，方程变为2x ≡ b，要求b为偶数
        }

        // 归一化主元行
        for (int j = i; j < n; ++j)
            a[i][j] = (a[i][j] * inv) % MOD;
        b[i] = (b[i] * inv) % MOD;

        // 消元
        for (int row = 0; row < n; ++row) {
            if (row != i && a[row][i] != 0) {
                int factor = a[row][i];
                for (int j = i; j < n; ++j)
                    a[row][j] = (a[row][j] - factor * a[i][j] + 4) % 4;
                b[row] = (b[row] - factor * b[i] + 4) % 4;
            }
        }
    }

    // 检查矛盾
    for (int i = 0; i < n; ++i) {
        if (b[i] != 0 && accumulate(a[i].begin(), a[i].end(), 0) == 0)
            return {};
    }
    return b;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= 4;
    }

    vector<vector<int>> relations(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x) relations[i].push_back(x);
        if (y) relations[i].push_back(y);
    }

    for (int t = 0; t < 4; ++t) {
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            d[i] = (t - a[i] + 4) % 4;
        }

        Matrix A = construct_matrix(n, relations);
        vector<int> x = gauss_mod4(A, d);

        if (!x.empty()) {
            vector<int> ops;
            for (int j = 0; j < n; ++j) {
                while (x[j]--) ops.push_back(j + 1);
            }

            // 验证解
            bool valid = true;
            vector<int> final_state = a;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    final_state[k] = (final_state[k] + A[k][j] * x[j]) % 4;
                }
            }
            for (int s : final_state) {
                if (s != t) valid = false;
            }

            if (valid) {
                for (int num : ops) cout << num << " ";
                cout << endl;
                return;
            }
        }
    }
    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
