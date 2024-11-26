#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, j;
    scanf("%d%*c", &n);
    // 动态分配存储字符串指针
    char** a = (char**)malloc(n * sizeof(char*));
    if (a == NULL) {
        exit(1);
    }
    // 动态分配存储每个字符串
    for (i = 0; i < n; i++) {
        a[i] = (char*)malloc(81 * sizeof(char));
        if (a[i] == NULL) {
            for (j = 0; j < i; j++) {
                free(a[i]);
            }
            free(a);
            exit(1);
        }
        fgets(a[i], 81, stdin);
    }
    // 初始化最小字符串为第一个字符串
    char* min = a[0];
    // 遍历字符串数组找到最小的字符串
    for (i = 0; i < n; i++) {
        if (strcmp(min, a[i]) > 0) {
            min = a[i];
        }
    }
    printf("Min is: %s", min);
    // 释放分配的内存
    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}