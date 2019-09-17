#include <stdio.h>
#include <cs50.h>

bool search(int n, int array[], int lower, int upper);
int findMidpoint(int lower, int upper);

int main(void)
{
    printf("Введите размер массива: ");
    int size = get_int();
    int array[size];
    for (int i=0; i<size; i++)
    {
        printf("Введите %i элемент массива: ", i+1);
        array[i] = get_int();
    }

    printf("Исходный массив: ");
    for (int i=0; i<size; i++)
    printf(" %i", array[i]);
    printf("\n");

    printf("Отсортированный массив:");
    for (int i=0; i < size; i++)
    {
        for (int j=i+1; j < size; j++)
        if (array[i]>array[j])
        {
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
        printf(" %i", array[i]);
    }
    printf("\n");

    printf("Введите искомое значение: ");
    int value = get_int();
    bool result = search(value, array, 0, size-1);
    if (result == true)
    printf("Это число есть\n");
    else
    printf("Этого числа нет\n");
}

int findMidpoint(int lower, int upper)
{
    int midpoint;
    if ((lower + upper)%2 == 0)
    midpoint = (lower + upper)/2;
    else
    midpoint = (lower + upper)/2+1;
    return midpoint;
}

bool search(int n, int array[], int lower, int upper)
{
    if (n > array[upper] || n < array[lower])
    return false;
    else
    {
        int midpoint;
        midpoint = findMidpoint(lower, upper);
        if (array[midpoint] < n)
        return search(n, array, midpoint+1, upper);
        else if (array[midpoint] > n)
        return search(n, array, lower, midpoint - 1);
        else if (array[midpoint] == n)
        return true;
        else
        return false;
    }
}