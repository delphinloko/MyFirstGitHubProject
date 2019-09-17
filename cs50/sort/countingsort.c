//
// Сортировка подсчётом массива целых чисел
// Числа вводятся с клавиатура как аргументы коммандной строки

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int findmax(int array[], int size); // прототип функции

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

    //поиск максимума массива
    int max = findmax(numbers, n) + 1;
    // сортировка
    int newnumbers[max]; // инициализация нового массива
    for (int i = 0; i < max; i++)
    {
        newnumbers[i] = 0;
    }
    //заполнение
    for (int i = 0; i < n; i++)
    {
        int a = numbers[i];
        newnumbers[a]++;
    }

    // вывод
    for (int i = 0; i < max; i++)
    {
        if (newnumbers[i] != 0)
        {
        int a = newnumbers[i];
        for (int j = 0; j < a; j++)
            {
                printf("%i ", i);
            }
        }
    }

    printf("\n");
    return 0;
}

// функция ищет максимум массива
int findmax(int array[], int size)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}