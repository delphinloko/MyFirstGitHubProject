#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>

bool compare (string str, string hash);

int main(int argc, string argv[])
{
    if (argc != 2) // проверка на 2 агрумента командной строки
    {
        printf("Введите одно значение ключа\n"); // если аргументов не 2 - вернули ошибку
        return 1;
    }
    // подготовка к работе
    string hash = argv[1];
    char salt[3];
    salt[0] = hash[0];
    salt[1] = hash[1];
    salt[2] = '\0';
    char pass[6] = "\0\0\0\0\0\0";
    // string pass = crypt("Hello", salt);
    // printf("%c\n", salt[0]);
    // printf("%c\n", salt[1]);
    // printf("%s\n", pass);

// строка с буквами алфавита
    char letters[52];
    for (int i = 0; i < 26; i++)
    {
        letters[i] = (char) (65 + i);
        letters[i + 26] = (char) (97 + i);
    }
        // printf("%s\n", letters);

// проверка 1-буквенного пароля
    for (int i = 0; i < 52; i++)
    {
        pass[0] = letters[i];
        if ( compare(crypt(pass, hash), hash) )
        {
            printf("%s\n", pass);
            exit(0);
        }
    }
    printf("First step ended\n");

// проверка 2-буквенного пароля
    for (int i = 0; i < 52; i++)
    {
        pass[0] = letters[i];
        for (int j = 0; j < 52; j++)
        {
            pass[1] = letters[j];
            if ( compare(crypt(pass, hash), hash) )
            {
                printf("%s\n", pass);
                exit(0);
            }
        }
    }
    printf("Second step ended\n");

// проверка 3-буквенного пароля
    for (int i = 0; i < 52; i++)
    {
        pass[0] = letters[i];
        for (int j = 0; j < 52; j++)
        {
            pass[1] = letters[j];
            for (int k = 0; k < 52; k++)
            {
                pass[2] = letters[k];
                if ( compare(crypt(pass, hash), hash) )
                {
                    printf("%s\n", pass);
                    exit(0);
                }
            }
        }
    }
    printf("Third step ended\n");

// проверка 4-буквенного пароля
    for (int i = 0; i < 52; i++)
    {
        pass[0] = letters[i];
        for (int j = 0; j < 52; j++)
        {
            pass[1] = letters[j];
            for (int k = 0; k < 52; k++)
            {
                pass[2] = letters[k];
                for (int l = 0; l < 52; l++)
                {
                    pass[3] = letters[l];
                    if ( compare(crypt(pass, hash), hash) )
                    {
                        printf("%s\n", pass);
                        exit(0);
                    }
                }
            }
        }
    }
    printf("Fourth step ended\n");

// проверка 5-буквенного пароля
    for (int i = 0; i < 52; i++)
    {
        pass[0] = letters[i];
        for (int j = 0; j < 52; j++)
        {
            pass[1] = letters[j];
            for (int k = 0; k < 52; k++)
            {
                pass[2] = letters[k];
                for (int l = 0; l < 52; l++)
                {
                    pass[3] = letters[l];
                    for (int m = 0; m < 52; m ++)
                    {
                        pass[4] = letters[m];
                        if ( compare(crypt(pass, hash), hash) )
                        {
                            printf("%s\n", pass);
                            exit(0);
                        }
                    }
                }
            }
        }
    }
    printf("Fifth step ended, couldn't crack password\n");

    printf("%s\n", crypt("YES", "50"));


    // // int y = strcmp(str,st);
    // pass[0] = letters[19];
    // pass[1] = letters[5];
    // printf("%s\n", crypt(pass, hash));
    // if ( compare(crypt(pass, hash), hash) )
    //     {
    //         printf("%s\n", pass);
    //     }


}

bool compare (string str, string hash)
{
    int counter = 0;
    for (int i = 0; i < strlen(hash); i++)
    {
        if (str[i] == hash[i])
        {
            counter++;
        }
        else
        {
            break;
        }
    }
    if (counter == strlen(hash))
    {
        return true;
    }
    else
    {
        return false;
    }
}