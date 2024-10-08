#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(char* src, char flag, int* count) {
    int cnt = 0;
    int len = strlen(src);
    char** pt = NULL;
    char* token_start = src;
    char* p = src;

    // 计算子字符串的数量
    while (*p) {
        if (*p == flag) {
            cnt++;
            // 跳过连续的分隔符
            while (*(p + 1) == flag) {
                p++;
            }
        }
        p++;
    }
    // 如果字符串末尾不是分隔符，也计入一个子字符串
    if (cnt == 0 || (p - src > 0 && *(p - 1) != flag)) {
        cnt++;
    }

    pt = (char**)malloc(sizeof(char*) * (cnt + 1));
    if (!pt) {
        perror("Failed to allocate memory for pointer array");
        exit(EXIT_FAILURE);
    }

    // 分割字符串
    cnt = 0;
    p = src;
    while (*p) {
        if (*p == flag) {
            // 分割点，复制之前的子字符串
            size_t len_token = p - token_start;
            pt[cnt] = (char*)malloc(len_token + 1);
            if (!pt[cnt]) {
                perror("Failed to allocate memory for token");
                for (int i = 0; i < cnt; i++) {
                    free(pt[i]);
                }
                free(pt);
                exit(EXIT_FAILURE);
            }
            strncpy(pt[cnt], token_start, len_token);
            pt[cnt][len_token] = '\0';
            cnt++;

            // 更新下一个子字符串的起始位置
            token_start = p + 1;
            while (*(p + 1) == flag) {
                p++;
            }
        }
        p++;
    }

    if (cnt == 0 || (p - src > 0 && *(p - 1) != flag)) {
        size_t len_token = p - token_start;
        pt[cnt] = (char*)malloc(len_token + 1);
        if (!pt[cnt]) {
            perror("Failed to allocate memory for last token");
            for (int i = 0; i < cnt; i++) {
                free(pt[i]);
            }
            free(pt);
            exit(EXIT_FAILURE);
        }
        strncpy(pt[cnt], token_start, len_token);
        pt[cnt][len_token] = '\0';
        cnt++;
    }

    pt[cnt] = NULL;
    *count = cnt;
    return pt;
}

int main() {
    char str[128];
    gets(str);
    // char* str = "this is a test  string";
    char flag = ' ';

    int count;
    char** result = split(str, flag, &count);

    for (int i = 0; i < count; i++) {
        printf("Token %d: %s\n", i, result[i]);
        free(result[i]);
    }
    free(result);

    printf("%d\n", count);

    return 0;
}