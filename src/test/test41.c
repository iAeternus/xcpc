#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void printArr(int arr[], int n);
void InsertSort(int arr[], int n);
void SetPos(int x, int y);

int main() {
    int arr[48] = {1, 15, 13, 10, 5, 34, 16, 14, 27, 18, 4, 21, 30, 6, 23, 17, 37, 18, 0, 23, 31, 24, 17, 7, 20, 23, 14, 9, 14, 3, 31, 2, 36, 33, 8, 10, 12, 28, 11, 19, 10, 2, 5, 6, 13, 15, 16, 18};

    printArr(arr, 48);
    SetPos(0, 0);
    InsertSort(arr, 48);

    return 0;
}

void SetPos(int x, int y) {
    COORD point = {x, y};                             //光标要设置的位置x,y
    HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE); //使用GetStdHandle(STD_OUTPUT_HANDLE)来获取标准输出的句柄
    SetConsoleCursorPosition(HOutput, point);         //设置光标位置
}

void printArr(int arr[], int n) {
    int max = 40;
    for (int i = max; i > 0; i--) //逐层扫描
    {
        for (int j = 0; j < n; j++) //数组逐个比较
        {
            if (arr[j] >= i)
                printf("+  ");
            else
                printf("   ");
        }
        printf("\n");
    }
}

void InsertSort(int arr[], int n) {
    int j;
    int tmp;
    for (int i = 0; i < n; i++) {
        tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;

        //单次排序操作后
        printArr(arr, n); // 打印图表
        Sleep(200);       //	控制帧速率
        SetPos(0, 0);     //	刷新画面
    }
}
