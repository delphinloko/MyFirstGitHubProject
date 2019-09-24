/****************************************************************************
 
* mario.c
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Draws a hill from Mario
*
 
***************************************************************************/

#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int Height = 0;
    do
    {
        printf("Enter positive height from 1 to 23:");
        Height = get_int("");
    }
    while (Height < 0 || Height > 23);

    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Height-i-1; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i+1; k++)
        {
            printf("#");
        }
        printf("#\n");
    }

}