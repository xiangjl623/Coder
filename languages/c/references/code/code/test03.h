#include <stdio.h>
#include <stdbool.h>

// **题目描述：** 编写一个函数，判断一个整数是否为素数。
 
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int test03() {
    int number;
    printf("请输入一个整数：");
    scanf("%d", &number);
    if (isPrime(number)) {
        printf("%d是素数。\n", number);
    } else {
        printf("%d不是素数。\n", number);
    }
    return 0;
}
