//
// Бинарный поиск по массиву
// Программа ищет число в отсортированном массиве методом бинарного поиска
// возвращает true, если найдено и false, если не найдено
// на вход подается искомое число, массив и границы поиска

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool search(int value, int values[], int leftbound, int rightbound); //прототип функции

int main(void)
{
    // задали число, которое ищем, массив и его размер.
    int number = 15;
    int array[] = {1,2,3,4,10,12,15,19,30,40};
    int size = 10;
    bool a = search(number, array, 0, size-1);
    if (a == true)
    {
        printf("Значение нашлось!\n");
    }
    else
    {
        printf("Значение не нашлось!\n");
    }

}


bool search(int value, int values[], int leftbound, int rightbound)
{

    // проверка, что число в границах массива
    if (value < values[leftbound] || value > values[rightbound])
    {
        return false;
    }

        int middle = (leftbound + rightbound) / 2;


        if (value > values[middle])
        {
            return search(value, values, middle+1, rightbound);
        }

        else if (value < values[middle])
        {
           return search(value, values, leftbound, middle-1);
        }

        else
        {
            return true;
        }

}