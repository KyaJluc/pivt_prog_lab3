#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void multipliers(int a, int b, int c)
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

void full_square(int a, int b, int c)
{
    if (b%2!=0)
    {
        printf("b нельзя нацело разделить на 2! (Метод пока не работает с плавающей точкой)");
        return;
    }
    if(a<0)
    {
        printf("Домножим уравнение на -1:\n");
        a*=-1;
        b*=-1;
        c*=-1;
        printf("%dx^2%s%dx%s%d\n",a,b>0?"+":"",b,c>0?"+":"",c);
    }
    if (a!=1) printf("\tВНИМАНИЕ!\nПри a!=1 могут быть ошибки в расчетах!\n");
    int mult = b/2;
    int sqrt_a=(int)sqrt(a);
    printf("Выделим в левой части полный квадрат:\n");
    printf("%dx^2%s%dx = %dx^2%s%d*2*x\n",a,b>0?"+":"",b,a,mult>0?"+":"",mult);
    printf("Чтобы получить полный квадрат, нужно прибавить %d^2:\n",abs(mult));
    printf("%dx^2%s%d*2*x+%d^2 = (x%s%d)^2\n",sqrt_a,mult>0?"+":"",mult,abs(mult),mult>0?"+":"",mult);
    //mult=abs(mult);
    printf("Преобразуем левую часть уравнения прибавляя и вычитая %d^2:\n",abs(mult));
    printf("%dx^2%s%dx%s%d = (x%s%d)^2-%d%s%d = (x%s%d)^2%s%d\n",a,b>0?"+":"",b,c>0?"+":"",c,
                                                    mult>0?"+":"",mult,(int)pow(mult,2),c>0?"+":"",c,
                                                    mult>0?"+":"",mult,(-(int)pow(mult,2)+c)>=0?"+":"",
                                                    -(int)pow(mult,2)+c);
    if(-(-pow(mult,2)+c)<0)
    {
        printf("Под знаком корня отрицательное число! Корней нет!\n");
        return;
    }
    if(-(-pow(mult,2)+c)==0)
    {
        printf("Таким образом, x%s%d=0\n",mult>0?"+":"",mult);
        printf("Значит, корень уравнения: x=%d.\n",-mult);
    }
    else
    {
        printf("Таким образом, x%s%d=%.0f или x%s%d=-%.0f\n",mult>0?"+":"",mult,sqrt(-(-(int)pow(mult,2)+c)),
                                                        mult>0?"+":"",mult,sqrt(-(-(int)pow(mult,2)+c)));
        printf("Значит, корни уравнения: x1=%0.f; x2=%.0f.\n",sqrt(-(-(int)pow(mult,2)+c))-mult,-sqrt(-(-(int)pow(mult,2)+c))-mult);
    }
}