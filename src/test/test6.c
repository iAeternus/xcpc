#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>

void menu() {
    printf("*****************\n");
    printf("**** 1. play ****\n");
    printf("**** 2. over ****\n");
    printf("*****************\n");
}

void chushihua(char board[11][11], int x, int y, char z) {
    int i = 0;
    int j = 0;

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            board[i][j] = z;
        }
    }
}

void xianshi(char board[11][11], int x, int y) {
    printf("----------ɨ��------------\n");
    int i = 0;
    int j = 0;
    for (i = 0; i <= 9; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= 9; i++) {
        printf("%d ", i);
        for (j = 1; j <= 9; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("-----------ɨ��-----------\n");
}

void shengcheng(char lei[11][11], int x, int y) {
    int count = 10;
    while (count) {
        int i = rand() % 9 + 1;
        int j = rand() % 9 + 1;
        if (lei[i][j] != '1') {
            lei[i][j] = '1';
        }
        count--;
    }
}

int finding(char lei[11][11], char mian[11][11], int x, int y) {
    int i = 0;
    int j = 0;
    int win = 0;
    while (win < 71) {
        //		if(i>=1 && i<=9 && j>=1 && j<=9)
        //		{
        printf("��������Ҫ��ѯ������ :");
        scanf("%d %d", &i, &j);
        if (lei[i][j] == '1') {
            printf("ʤ���˱��ҳ�������������������\n");
            xianshi(lei, 9, 9);
            break;
        } else {
            int m = lei[i][j + 1] + lei[i][j - 1] + lei[i + 1][j] + lei[i + 1][j - 1] + lei[i + 1][j + 1] + lei[i - 1][j] + lei[i - 1][j - 1] + lei[i - 1][j + 1] - 8 * '0';
            
            
            
            mian[i][j] = m + '0';
            xianshi(mian, 9, 9);
            win++;
        }
        //		}
        //		else
        //		{
        //			printf("���������룡");
        //		}
        //

        if (win == 71) {
            printf("����Ӯ�ñ������Ǳ�Ȼ��\n");
        }
    }
}

void game() {
    //	  ��������
    char lei[11][11];
    char mian[11][11];
    //	  ��ʼ������
    chushihua(lei, 9, 9, '0');
    chushihua(mian, 9, 9, '*');
    //	  ������
    shengcheng(lei, 9, 9);
    //    ��ʾ����
    //	  xianshi(lei,9,9);
    xianshi(mian, 9, 9);
    //    �Ų���
    finding(lei, mian, 9, 9);
}

int main() {
    srand((unsigned int)time(NULL));
    int p = 0;
    do {
        menu();
        printf("��ѡ�� :");
        scanf(" %d", &p);
        switch (p) {
            case 1:
                printf("��Ϸ��ʼ��\n");
                game();
                break;
            case 0:
                printf("�˳���Ϸ��");
                break;
            default:
                printf("����������������룡");
        }

    } while (p);

    return 0;
}