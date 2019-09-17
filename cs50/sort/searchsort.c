//
// Сортировка выбором массива целых чисел
// Числа вводятся с клавиатура как аргументы коммандной строки

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int n = argc - 1;
    int numbers[n];

    // считывание массива и проверка на правильность
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(argv[i+1]); j++)
        {
            if (isdigit(argv[i+1][j])==0)            // проверяем, является ли числом введёные в cmd символы
            {
                printf("Вы ввели массив не Int чисел!\n");
                return 1;
            }
        }
        numbers[i] = atoi(argv[i+1]);
    }

    //сортировка
    for (int i = 0; i < (n-1); i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (numbers[j] < numbers[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int a = numbers[i];
            numbers[i] = numbers[min];
            numbers[min] = a;
        }
    }


    //вывод массива
    for (int i = 0; i < n; i++)
    {
        printf("%i ", (int) numbers[i]);
    }

    printf("\n");
    return 0;
}

