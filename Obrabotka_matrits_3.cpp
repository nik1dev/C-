/* Транспонировать в матрице квадрат, в правом верхнем углу которого 
расположен самый первый ноль. Определить, сколько всего нулей в 
исходной матрице, и, если их больше чем количество строк в матрице, 
заменить нули на это количество.*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "iostream"
#define s 100
 
int main(int argc, char const *argv[])
{  setlocale(0,"RUS");
    int size = 0;
    int elem = 0;
    int n = 0;         
    int xKrd = 0, yKrd = 0;
    int xZerKord = 0, yZerKord = 0;
    int kzero = 0;  
    int a[s][s] = {0};
    int b[s][s];
 
    printf(" Способ создания матрицы:\n");
    printf(" 1. Квадратная матрица\n");
    printf(" 2. X и Y вводятся с клавиатуры.\n");
    printf(" 3. С файла\n");
    printf("\nВариант - "); scanf("%d",&size);
    while (size > 3 || size < 1)               
    {                                                      
        printf("\nВариант - "); scanf("%d",&size);      
    }                                                      
    if (size != 3)
    {
        printf(" \n\nЭлементы матрицы \n");
        printf(" 1. Вводятся с клавиатуры.\n");
        printf(" 2. Генерируются случайно.\n");
        printf("\nВариант - "); scanf("%d",&elem);
        while(elem < 1 || elem > 2)        
        {                                                      
            printf(">!< Введите число больше 0 и меньше 3\n");
            printf("\nВариант - "); scanf("%d",&elem);   
        }                                                      
    }
    if ((size != 3) && elem == 1)
    {
        if (size == 1)
        {
            printf("\n Сторона матрицы\n N = "); scanf("%d",&n); 
            while (n<=0)
            {
                printf("\n Сторона матрицы\n N = "); scanf("%d",&n); 
            }  
            xKrd = n;                                                        
            yKrd = n;                                                      
        }
        else
        {
            printf("\nX = "); scanf("%d", &xKrd);
            printf("\nY = "); scanf("%d", &yKrd);
            while (yKrd < 0)
            {
                printf("Y должен быть больше 0\n");
                printf("\nY = "); scanf("%d", &yKrd);
                  }
            while (xKrd < 0)
            {
                printf("X должен быть больше 0\n");
                printf("\nX = "); scanf("%d", &xKrd);
            }
        }
        printf("\n");
        for (int y = 0; y < yKrd; ++y)
        {
            for (int x = 0; x < xKrd; ++x)
            {
                printf("Элемент - [%d][%d] ",y,x); scanf("%d", &a[y][x]);
                if (kzero < 1)
                {
                    if (a[y][x] == 0)
                    {  
                        yZerKord = y;
                        xZerKord = x;
                        kzero++;
                    }
                }
            }
        }
    }
    if ((size != 3) && elem==2)
    {
        if (size == 1)
        {
            printf("\nN = "); scanf("%d",&n);
            xKrd=n;                      
            yKrd=n;
            while (n <= 0)
            {
                printf("Сторона не может быть меньше 0\n");
                printf("\n Сторона квадратной матрицы\n N = "); 
scanf("%d",&n);
            }                        
        }
        else
        {
            printf("\nX = "); scanf("%d",&xKrd);
            printf("\nY = "); scanf("%d",&yKrd);
            while (yKrd < 0)
            {
                printf("Y должен быть больше 0\n");
                printf("\nY = "); scanf("%d",&yKrd);
            }
            while (xKrd < 0)
            {
                printf("X должен быть больше 0\n");
                printf("\nX = "); scanf("%d", &xKrd);
            }
        }
 
        srand(time(NULL));
        int min = 0;
        int max = 0;
        printf("Генерация \n c Min - ");
        scanf("%d", &min);
        printf("по Max - ");
        scanf("%d", &max);  max++;
         for (int y = 0; y < yKrd; ++y)
        {
            for (int x = 0; x < xKrd; ++x)
            {
                a[y][x] = min + rand() % max;
                if (kzero < 1)       
                {                          
                    if (a[y][x] == 0)  
                    {                      
                        xZerKord=x;        
                        yZerKord=y;        
                        kzero++;       
                    }                      
                }                      
            }
        }
    }
 
    if (size == 3)
    {
        FILE *f = fopen("b.txt", "r");
        if (f != NULL)
            {
                printf("Введите размер матрицы в файле\n");
                printf("X = "); scanf("%d",&xKrd);
                printf("Y = "); scanf("%d",&yKrd);
                for (int y = 0; y < yKrd; ++y)
                    {
                        for (int x = 0; x < xKrd; x++)
                            {
                                fscanf(f,"%d",&a[y][x]);
                                if (kzero < 1)     
                                {                          
                                    if (a[y][x] == 0)  
                                    {                      
                                        xZerKord = x;          
                                        yZerKord = y;          
                                        kzero++;       
                                    }                      
                                }                          
                            }
                    }
            }
            else
            {
                printf("Создайте файл с матрицей - 'b.txt'\n");
                return 0;
            }
        fclose(f);
    }
 
    printf("\n\n --------------------Задание №1-------------------- \n");
    printf("   Транспонировать в матрице квадрат, в правом верхнем углу которого расположен самый первый ноль.\n\n");
    if (kzero == 1)
    {
        printf("   1.Исходная матрица\n");
        for (int y = 0; y < yKrd; ++y)
        {
            for (int x = 0; x < xKrd; ++x)
            {
                printf("   %d",a[y][x]);
                    }
            printf("\n");
        }
       
        printf("\n   2.Матрица по первый 0\n");
        for (int y = yZerKord, i = 0; y <= xZerKord + yZerKord ; ++y, ++i)
        {
            for (int x = 0, j = 0; x <= xZerKord; ++x, ++j)
            {
                b[i][j] = a[y][x];
                printf("   %d",a[y][x]);
            }
            printf("\n");
        }
 
        printf("\n   3.Транспонированная матрица\n");
        for (int y = 0; y <xZerKord+1; ++y)
        {
            for (int x = 0; x < xZerKord+1; ++x)
            {
                printf("   %d", b[x][y]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("В матрице отсутствует 0\n\n");
        printf("   Исходная матрица\n\n");
        for (int y = 0; y < yKrd; ++y)
        {
            for (int x = 0; x < xKrd; ++x)
            {
                printf("   %d",a[y][x] );
            }
            printf("\n");
        }
    }
 
    printf("\n\n --------------------Задание №2-------------------- \n");
    printf("   Определить, сколько всего нулей в исходной матрице, и, если их больше чем количество строк в матрице, заменить нули на это количество.\n\n");
    for (int y = 0; y < yKrd; ++y)
        {
            for (int x = 0; x < xKrd; ++x)
            {
                if (a[y][x]==0)
                {
                    kzero++;
                }
            }
        }
    if (kzero > yKrd)
    {
        printf("   1.Исходная матрица\n");
        for (int y = 0; y < yKrd; ++y)
        {
            for (int x = 0; x < xKrd; ++x)
            {
                printf("   %d", a[y][x] );
                if (a[y][x] == 0)      
                  {  
                    a[y][x] = yKrd;
                }                          
            }
            printf("\n");
        }
        printf("\n\n\n   2.Все нули заменены на количество строк (%d)\n",yKrd);
        for (int y = 0; y < yKrd; ++y)
        {
            for (int x = 0; x < xKrd; ++x)
            {
                printf("   %d",a[y][x] );
            }
            printf("\n");
        }
 
        printf("\n  Нулей - %d\n",kzero);
        printf("  Количество строк - %d \n",yKrd);
    }
    else
    {
        printf("Условие (количество строк < количества нулей) не соблюдено \n\n\n");
        printf("   Исходная матрица\n");
        for (int y = 0; y < yKrd; ++y)
        {
            for (int x = 0; x < xKrd; ++x)
            {
                printf("   %d",a[y][x] );
            }
            printf("\n");
        }
        printf("\n   Нулей - %d\n",kzero);
        printf("   Количество строк - %d \n",yKrd);
    }
    return 0;
}
