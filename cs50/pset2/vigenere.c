/****************************************************************************
 
* vigenere.c
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Cipher text via vigenere cipher
*
 
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int get_key(string word, int counter);// прототип функцииc

int main(int argc, string argv[])
{
    if (argc != 2) // проверка на 2 агрумента командной строки
    {
        printf("Введите одно значение ключа\n"); // если аргументов не 2 - вернули ошибку
        return 1;
    }
    string key = argv[1];  // получили ключ

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isalpha(key[i]))
        {
        }
        else
        {
            printf("Введите корректное значение ключа\n");
            return 1;
        }
    }

    printf("plaintext: ");
    string plaintext = get_string(""); // запросили строку текста
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext), j = 0; i < n; i ++) //проходимся по тексту
    {
        if (isupper(plaintext[i])) // что делать, если верхняя буква
        {
            int alphabetic_index0 = plaintext[i] - 65;
            int alphabetic_index1 = (alphabetic_index0 + get_key(key, j)) % 26;
            j++;
            int cipherletter = 65 + alphabetic_index1;
            printf("%c", (char) cipherletter);
        }
        else if (islower(plaintext[i])) // что делать, если нижняя буква
        {
            int alphabetic_index0 = plaintext[i] - 97;
            int alphabetic_index1 = (alphabetic_index0 + get_key(key, j)) % 26;
            j++;
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


// число, на которое сдвигаем нашу букву - kj
int get_key(string word, int counter)
{
    int n = strlen(word);
    int index = counter % n;
    if (isupper(word[index]))
    {
        return (word[index] - 65);
    }
    else if (islower(word[index]))
    {
        return (word[index] - 97);
    }
    else
    {
        printf("Ошибочный ключ\n");
        return 1;
    }
}