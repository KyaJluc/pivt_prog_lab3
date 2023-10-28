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

void formula(int a, int b, int c)
{
    printf("Рассчитаем дискриминант D:\n");
    printf("\tВНИМАНИЕ!\nПри получении не целого квадратного корня из D могут быть ошибки в расчетах!\n");
    int D = pow(b,2)-4*a*c;
    if (D<0)
    {
        printf("Дискриминант отрицательный! Корней нет!\n");
        return;
    }
    if (D==0)
    {
        int x = -b/(2*a);
        printf("Дискриминант равен нулю! Уравнение имеет корень: x=%d\n",x);
    }
    else
    {
        int x1 = (-b + (int)sqrt(D))/(2*a);
        int x2 = (-b - (int)sqrt(D))/(2*a);
        printf("Дискриминант положительный! Уравнение имеет корни: x1=%d; x2=%d\n",x1,x2);
    }
}

void vieta(int a, int p, int q)
{
    printf("По теореме Виета корни уравнения удовлетворяют системе:\n");
    printf("\tx1*x2 = %d\n",q);
    printf("\tx1 + x2 = %d\n",-p);
    if (a!=1)
    {
        if (a!=1) printf("\tВНИМАНИЕ!\nМогут быть ошибки в расчетах, если b и c не делятся нацело на а!\n");
        printf("Приведем к нужному виду, разделив уравнение на а\n");
        p/=a;
        q/=a;
    }
    int x1=0, x2=0;
    if (q>0)
    {
        printf("Так как свободый член q>0, то уравнение имеет два одинаковых по знаку корня\n");
        printf("Так как p%s0, оба корня %s\nСледовательно: ",p>0?">":"<",p>0?"отрицательны":"положительны");
        while(x1*x2!=q || x1+x2!=-p)
        {
            p>0?x1--:x1++;
            x2=-p-x1;
        }
    }
    else
    {
        printf("Так как свободый член q<0, то уравнение имеет два разных по знаку корня\n");
        printf("Так как p%s0, больший по модулю корень %s\nСледовательно: ",p>0?">":"<",p>0?"отрицателен":"положителен");
        while(x1*x2!=q || x1+x2!=-p)
        {
            p>0?x1++:x1--;
            x2=-p-x1;
        }
    }
    printf("x1=%d; x2=%d\n",x1,x2);
}

void perebroska(int a, int b, int c)
{
    printf("Умножим обе части уравнения на а(%d), где ax=y\nПо теореме Виета:\n",a);
    printf("\ty1*y2 = a*c = %d\n",a*c);
    printf("\ty1+y2 = -b = %d\n",-b);
    int y1=0,y2=0;
    if (a*c>0)
    {
        while(y1*y2!=a*c || y1+y2!=-b)
        {
            b>0?y1--:y1++;
            y2=(-b)-y1;
        }
    }
    else
    {
        while(y1*y2!=a*c || y1+y2!=-b)
        {
            b>0?y1++:y1--;
            y2=(-b)-y1;
        }
    }
    printf("Находим y1 и y2: y1=%d; y2=%d\n",y1,y2);
    printf("Получим корни: x1=y1/a=%d; x2=y2/a=%d\n",y1/a,y2/a);
}