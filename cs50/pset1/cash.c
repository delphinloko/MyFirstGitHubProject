/****************************************************************************
 
* cash.c
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Count number of coins to change
*
 
***************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    float greedy = 0;
    do
    {
        printf("How much change is owed?\n");
        greedy = get_float("");
    }
    while (greedy <= 0);
int cents = round(greedy*100);
int coins = 0;

coins = coins + cents/25;
cents = cents % 25;
coins = coins + cents/10;
cents = cents % 10;
coins = coins + cents/5;
cents = cents % 5;
coins = coins + cents;
printf("%i\n", coins);

}