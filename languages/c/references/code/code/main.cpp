#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "test01.h"
#include "test02.h"
#include "test03.h"
#include "test04.h"
#include "test05.h"
#include "test10.h"

//int main(int argc, char** argv) {
//	test10();
//	return 0;
//}
//
//float sum(int n) {
//  float sum = 0;
//  return sum;
//}
//
//
//int main()
//{
//    printf("sum=%f\n", sum(100));
//    return 0;  
//}

//	for (i=1;i<100,i++)
//        while(i%==1)
//        n = 0+i*i
//        /********** End **********/
//    }
double fun(double m)
{
    /**********Program**********/
    double c;
    c=5.0/9.0*(m-32); 
    return c;
    /* 请在此处编写代码 */
    /********** End **********/
}

void test11()
{
    double c, f;
    printf("请输入一个华氏温度：");
    scanf("%lf", &f);
    c = fun(f);
    printf("摄氏温度为：%5.2lf\n", c);
}

int main () {
	test11();
	return 0;
}
