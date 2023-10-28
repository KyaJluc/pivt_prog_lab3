#include "my_func.h"

void main()
{
    printf("\nПРОГРАММА ДЛЯ РЕШЕНИЯ КВАДРАТНЫХ УРАВНЕНИЙ\n\n\tax^2+bx+c=0\n\n");
    int exit=0, a, b, c;
    char input[10];
    printf("Введите коэффиценты уравнения.\n\n\tВНИМАНИЕ!\nЛюбое не цифровое значение = 0!\nВещественные берутся без дробной части!\n\n");
    printf("Введите коэффицент а: ");
    scanf("%s[^\n]\n",input);
    sscanf(input, "%d", &a);
    printf("Введите коэффицент b: ");
    scanf("%s[^\n]\n",input);
    sscanf(input, "%d", &b);
    printf("Введите коэффицент c: ");
    scanf("%s[^\n]\n",input);
    sscanf(input, "%d", &c);
    if(a==0 || b==0 || c==0)
    {
        printf("Это уравнение решается без использования способов в этой программе!\n\n");
    }
    printf("\nВаше уравнение: %dx^2%s%dx%s%d=0\n\n",a,b>0?"+":"",b,c>0?"+":"",c);
    printf("Выберите способ решения:\n\n");
    printf("1 - Разложение левой части уравнения на множители\n");
    printf("2 - Метод выделения полного квадрата\n");
    printf("3 - Решение квадратных уравнений по формуле\n");
    printf("4 - Решение уравнений с использованием теоремы Виета\n");
    printf("5 - Решение уравнений способом «переброски»\n");
    printf("6 - Свойства коэффициентов квадратного уравнения\n");
    printf("7 - Графическое решение квадратного уравнения\n");
    printf("8 - Решение квадратных уравнений с помощью циркуля и линейки\n");
    printf("9 - Решение квадратных уравнений с помощью  номограммы\n");
    printf("10 - Геометрический способ решения квадратных  уравнений\n");
    printf("0 || другое значение - ВЫХОД\n");
    while (!exit)
    {
        int mode=0;
        printf("\nСпособ: ");
        scanf("%s[^\n]\n\n",input);
        sscanf(input, "%d", &mode);
        if(mode>10) mode=0;
        switch (mode)
        {
            case 1:
                multipliers(a,b,c);
                break;
            case 2:
                full_square(a,b,c);
                break;
            case 3:
                formula(a,b,c);
                break;
            case 4:
                vieta(a,b,c);
                break;
            case 5:
                perebroska(a,b,c);
                break;
            case 6:
                index_props(a,b,c);
                break;
            case 0:
                printf("Выход из программы...\n");
                exit=1;
                break;          
            default:
                printf("Графические способы решения находятся в разработке!\n");
                break;
        }
    }
}