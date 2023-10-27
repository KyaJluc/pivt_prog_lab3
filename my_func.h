#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void first_case(int a, int b, int c)
{
    int mn_1=0, mn_2=0, exp1=c, exp2=b;
    if (a!=1)
    {
        if(c%a!=0 && b%a!=0)
        {
            printf("При делении c и b на a не получается целое число! МЕТОД В РАЗРАБОТКЕ...\n");
            return;
        }
        printf("Разделим уравнение на а:\n");
        exp1=c/a;
        exp2=b/a;
        printf("x^2%s%dx%s%d\n",exp2>0?"+":"",exp2,exp1>0?"+":"",exp1);
    }
    while(mn_1+mn_2!=exp2 || exp1%mn_1!=0)
    {   
        exp2>0?mn_1++:mn_1--;
        mn_2=exp1/mn_1;
        if (abs(mn_1)>abs(exp1)) 
        {
            printf("Общие множители не найдены! (Метод работает только с целыми множителями)\n");
            return;
        }
    }
    printf("Разложим левую часть на множители:\n");
    printf("x^2%s%dx%s%dx%s%d = x(x%s%d)%s%d(x%s%d) = (x%s%d)(x%s%d)\n",mn_2>0?"+":"",mn_2,mn_1>0?"+":"",
                            mn_1,exp1>0?"+":"",exp1,mn_2>0?"+":"",mn_2,mn_1>0?"+":"",mn_1,mn_2>0?"+":"",
                            mn_2,mn_1>0?"+":"",mn_1,mn_2>0?"+":"",mn_2);
    printf("Следовательно, уравнение можно переписать как:\n");
    printf("(x%s%d)(x%s%d)=0\n",mn_1>0?"+":"",mn_1,mn_2>0?"+":"",mn_2);
    if (mn_1==mn_2)
    {
        printf("Значит, корень уравнения один: x=%d.\n",-mn_1);
    }
    else
    {
        printf("Значит, корни уравнения: x1=%d; x2=%d.\n",-mn_1,-mn_2);
    }

}
// x2-2x-x-2 = x(x-2)-(x-2)