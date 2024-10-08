#include <stdio.h>
#include <string.h>

// char ch[1000];

// int main() {
//     gets(ch);
//     int n = strlen(ch);
//     int cnt = ch[0] == ' ' ? 0 : 1;

//     for (int i = 0; i < n; i++) {
//         if (ch[i] == ' ' && ch[i + 1] != ' ') {
//             cnt++;
//         }
//     }

//     if (ch[n - 1] == ' ') {
//         --cnt;
//     }

//     printf("%d\n", cnt);
// }

int main() {
    char str[100];
    gets(str);
    // puts(str);

    // int len = strlen(str);
    // for(int i = 0; i < len; ++i) {
    //     // ...
    //     // printf("%c\n", str[i]);
    // }

    for(int i = 0; str[i]; ++i) {
        printf("%c\n", str[i]);
    }
}