// **题目描述：** 编写一个函数，输出前N个斐波那契数。

#include <stdio.h>

void printfFibonacci(int n) {
    int fib1 = 0, fib2 = 1, next;
    for (int i = 1; i <= n; i++) {
        printf("%d ", fib1);
        next = fib1 + fib2;
        fib1 = fib2;
        fib2 = next;
    }
    printf("\n");
}

int test04() {
    int N;
    printf("请输入要输出的斐波那契数的个数N：");
    scanf("%d", &N);
    printfFibonacci(N);
    return 0;
}
