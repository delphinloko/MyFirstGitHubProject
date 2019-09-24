/****************************************************************************
 
* caesar.c
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Cipher text via caesar cipher
*
 
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc != 2) // проверка на 2 агрумента командной строки
    {
        printf("Введите одно значение ключа\n"); // если аргументов не 2 - вернули ошибку
        return 1;
    }

    int key = atoi(argv[1]);  // вытащили ключ из аргумента
    printf("plaintext: ");
    string plaintext = get_string(); // запросили строку текста
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i ++) //проходимся по тексту
    {
        if (isupper(plaintext[i])) // что делать, если верхняя буква
        {
            int alphabetic_index0 = plaintext[i] - 65;
            int alphabetic_index1 = (alphabetic_index0 + key) % 26;
            int cipherletter = 65 + alphabetic_index1;
            printf("%c", (char) cipherletter);
        }
        else if (islower(plaintext[i])) // что делать, если нижняя буква
        {
            int alphabetic_index0 = plaintext[i] - 97;
            int alphabetic_index1 = (alphabetic_index0 + key) % 26;
            int cipherletter = 97 + alphabetic_index1;
            printf("%c", (char) cipherletter);
        }
        else
        {
            printf("%c", (char) plaintext[i]);
        }
    }

    printf("\n");
    return 0;
}
