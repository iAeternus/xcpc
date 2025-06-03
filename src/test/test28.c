#include <stdio.h>

int str_len(char s[]) {
    int i = 0, j = 0;
    while(s[j] != '\0') ++j;
    return j - i;
}

int main() {
    printf("%d\n", str_len("ABCDEF"));
}