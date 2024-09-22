/*
4 3
0 2 2 0 2
0 1 1 -1
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 10;
const double pi = acos(-1);
#define endl '\n'
complex<double> A[N], B[N], C[N];
int pos[N];

void FFT_Iteration(complex<double> A[], int n) {
    // bit reversal
    pos[0] = 0;
    // cout << "after reversal ";
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i / 2] / 2 + (i % 2) * n / 2;
        // cout << pos[i] << " ";
    }
    // cout << endl;
    for (int i = 0; i < n; i++)
        if (i < pos[i])
            swap(A[i], A[pos[i]]);
    // for (int i = 0; i < n; i++)
    // cout << A[i] << " ";
    // cout << endl;
    // butterfly diagram
    for (int l = 2; l <= n; l *= 2) {
        complex<double> W, Wk;
        for (int i = 0; i < n; i += l) {
            Wk = 1;
            W.real(cos(pi * 2 / l));
            W.imag(-sin(pi * 2 / l));
            for (int j = 0; j < l / 2; j++) {
                // A[i+j]=A[i+j]+Wk*A[i+j+l/2];
                // A[i+j+l/2]=A[i+j]-Wk*A[i+j+l/2];
                complex<double> x = A[i + j], y = A[i + j + l / 2] * Wk;
                A[i + j] = x + y;
                A[i + j + l / 2] = x - y;
                Wk *= W;
            }
        }
    }
}

void IFFT_Iteration(complex<double> A[], int n) {
    // bit reversal
    pos[0] = 0;
    // cout << "after reversal ";
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i / 2] / 2 + (i % 2) * n / 2;
        // cout << pos[i] << " ";
    }
    // cout << endl;
    for (int i = 0; i < n; i++)
        if (i < pos[i])
            swap(A[i], A[pos[i]]);
    // for (int i = 0; i < n; i++)
    // cout << A[i] << " ";
    // cout << endl;
    // butterfly diagram
    for (int l = 2; l <= n; l *= 2) {
        complex<double> W, Wk;
        for (int i = 0; i < n; i += l) {
            Wk = 1;
            W.real(cos(pi * 2 / l));
            W.imag(sin(pi * 2 / l));
            for (int j = 0; j < l / 2; j++) {
                // A[i+j]=A[i+j]+Wk*A[i+j+l/2];
                // A[i+j+l/2]=A[i+j]-Wk*A[i+j+l/2];
                complex<double> x = A[i + j], y = A[i + j + l / 2] * Wk;
                A[i + j] = x + y;
                A[i + j + l / 2] = x - y;
                Wk *= W;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        cin >> A[i];
    for (int i = 0; i <= m; i++)
        cin >> B[i];
    int N = 1;
    while (N <= n + m + 1)
        N *= 2;
    FFT_Iteration(A, N);
    FFT_Iteration(B, N);
    for (int i = 0; i < N; i++)
        C[i] = A[i] * B[i];
    IFFT_Iteration(C, N);
    for (int i = 0; i < n + m + 1; i++)
        cout << int(C[i].real() / N + 0.5) << " ";
    // cout << round(C[i].real() / N ) << " "; 速度慢，且有-0问题
    return 0;
}
