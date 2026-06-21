#include <stdio.h>

// **题目描述：** 找出所有的三位水仙花数（各位数字的立方和等于该数本身），每行显示5个数。
int test02() {
    int a, m, n, q, p = 1;
    a = 100;
    while (a < 1000) {
        m = a / 100;
        n = a / 10 % 10;
        q = a % 10;
        if (a == m * m * m + n * n * n + q * q * q) {
            printf("%5d", a);
            if (p % 5 == 0)
                printf("\n");
            p++;
        }
        a++;
    }
    return 0;
}
