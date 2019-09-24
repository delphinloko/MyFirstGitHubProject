/****************************************************************************
 
* water.c
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Demostrates simple math operations
*
 
***************************************************************************/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Введите, пожалуйста, число минут: \n");
    int a = get_int("");
    printf("Вам потребуется %i бутылок(ки) \n", a*12);
}