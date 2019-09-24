/****************************************************************************
 
* mergesort.c
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Realize algorithm of mergesort
*
 
***************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void merge(int array[], int start, int middle, int end);
void sort (int array[], int start, int end);

int main(int argc, string argv[])
{
    int end = argc - 1;
    int array[end];
    // считывание массива и проверка на правильность
    for (int i = 0; i < end; i++)
    {
        for (int j = 0; j < strlen(argv[i+1]); j++)
        {
            if (isdigit(argv[i+1][j])==0)            // проверяем, является ли числом введёные в cmd символы
            {
                printf("Вы ввели массив не Int чисел!\n");
                return 1;
            }
        }
        array[i] = atoi(argv[i+1]);
    }

    int start = 0;

    sort (array, start, end);

    for (int i = 0; i < end; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
    return 0;
}

void sort (int array[], int start, int end)
{
    if (end > start)
    {
        int middle = (start + end) / 2;

        sort(array, start, middle);
        sort(array, middle+1, end);

        merge(array, start, middle, end);
    }
}


void merge(int array[], int start, int middle, int end)
{
    //задали размеры доп массивов, сами массивы и счётчики.
    int s1 = middle - start + 1;
    int s2 = end - middle;
    int arr1[s1];
    int arr2[s2];
    int arr[s1+s2];
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;

    // разбили входной массив на две части
    for (int i = 0; i<s1; i++)
    {
        arr1[i] = array[start + i];
    }
    for (int i = 0; i<s2; i++)
    {
        arr2[i] = array[middle + 1 + i];
    }

    //склеиваем
        while (c2 < s2 && c1 < s1)
    {
        if (arr1[c1] >= arr2[c2])
        {
            arr[c0] = arr2[c2];
            c2++;
        }
        else
        {
            arr[c0] = arr1[c1];
            c1++;
        }
        c0++;
    }

    while (c2 < s2)
    {
        arr[c0] = arr2[c2];
        c0++;
        c2++;
    }

    while (c1 < s1)
    {
        arr[c0] = arr1[c1];
        c0++;
        c1++;
    }

    //перезапишем склеенный массив в изначальный
    for (int i = 0; i < s1+s2; i++)
    {
        array[start + i] = arr[i];
    }
}