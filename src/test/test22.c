#include <stdio.h>

// since c99
void func(int n, int m, int a[n][m]) {

}



int main() {
    int n = 5;
    int a[n][n];
    func(a, n, n);
}