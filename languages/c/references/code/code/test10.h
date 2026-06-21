#include <stdio.h>

int test10() {
    int x1, x2 = 1, day;
    for (day = 9; day > 0; day--) {
        printf("第%d天的桃子数：%d\n", day, x2);
        x1 = 2 * (x2 + 1);
        x2 = x1;
    }
    printf("第一天的桃子数：%d\n", x1);
    return 0;
}
