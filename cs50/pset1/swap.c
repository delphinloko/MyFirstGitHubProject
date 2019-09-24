/****************************************************************************
 
* swap.c
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Demonstrates swap problem in c and neсesity of pointers
*
 
***************************************************************************/

#include <stdio.h>

void swap(int a, int b); //Прототип функции swap

int main(void)
{
     int x = 1, y = 2;
     swap(y, x);
     printf("x is %i\n", x);
     printf("y is %i\n", y);
}

void swap(int a, int b)
{
     int tmp = a;
     a = b;
     b = tmp;
}