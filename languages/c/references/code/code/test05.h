// **题目描述：** 打印由星号(*)组成的五层递加三角形，每层星号比上一层多两个，居中显示。

#include <stdio.h>

int test05() {
    int a, b, n = 1;
    while (n <= 5) {
        a = 1, b = 1;
        while (a <= 5 - n) {
            printf(" ");
            a++;
        }
        while (b <= 2 * n - 1) {
            printf("*");
            b++;
        }
        printf("\n");
        n++;
    }
    return 0;
}
