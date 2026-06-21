#include <stdio.h>

// 编写一个C语言程序，要求用户输入一个年份，程序判断并输出该年份是否是闰年。

int test01() {
    int a;
    printf("请输入您要判断的年份：");
    scanf("%d", &a);
    if (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0))
        printf("%d是闰年.\n", a);
    else {
    	printf("%d不是闰年.\n", a);
	}
    return 0;
}
