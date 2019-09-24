/****************************************************************************
 
* files.c
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Demonstrates loading data from file into hashtable and unloading it
*
 
***************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#define HASHSIZE 5

typedef struct sllist
{
    char val [45];
    struct sllist* next;
}
sllnode;
void del(sllnode* HashTable[], char* key);
void showtable (sllnode* HashTable[]);
void create(sllnode* HashTable[]);
void destroy(sllnode* HashTable[]);
unsigned int hash(char* string);
bool find(sllnode* HashTable[], char* key);
char s [45];

int main(void)
{
    FILE* pFile;
    pFile = fopen ("text.txt","r");
    
    sllnode* HashTable[HASHSIZE];
    create(HashTable);
    
    while (fscanf (pFile, "%s", s) != EOF)
    {
        // hash-function
        int index = (toupper (s[0]) - 'A') % HASHSIZE;
        // insert
        sllnode* ptr = malloc(sizeof(sllnode));
        // проверка на ошибку
        if (ptr == NULL)
        {
            printf("Error1\n");
            exit(1);
        }
        strcpy(ptr->val, s);
        ptr->next = HashTable[index]->next;
        HashTable[index]->next = ptr;
    }
    
    showtable (HashTable);
    destroy(HashTable);
    fclose(pFile);
}

// удаляем таблицу и очищаем память
void destroy(sllnode* HashTable[])
{
    // проходимся по каждому связанному списку и удаляем его элементы
    for (int i = 0; i < HASHSIZE; i++)
    {
        sllnode* ptr = HashTable[i];
        while (ptr->next != NULL)
        {
            del(HashTable, ptr->next->val);
        }
    }
    // удаляем основу хэш-таблицы
    for (int i = 0; i < HASHSIZE; i++)
    {
        free(HashTable[i]);
    }
}

// удаляет из таблицы значение по ключу key
void del(sllnode* HashTable[], char* key)
{
    // проверка, существует ли значение в таблице
    if (find(HashTable, key))
    {
        int index = hash(key);
        sllnode* ptrprev = HashTable[index];
        sllnode* ptrcurr = HashTable[index]->next;

        while (ptrcurr->val != key)
        {
            ptrcurr = ptrcurr->next;
            ptrprev = ptrprev->next;
        }
        ptrprev->next = ptrcurr->next;
        free(ptrcurr);
    }
}

// выводит всю хеш-таблицу
void showtable (sllnode* HashTable[])
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        sllnode* ptr = HashTable[i];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            printf("%s ", ptr->val);
        }
        printf("\n");
    }
}

//  hash function по первой букве слова
unsigned int hash(char* string)
{
    int hash = toupper (string[0]) - 'A';
    return hash % HASHSIZE;
}

// ищет значение в хэш таблице
bool find(sllnode* HashTable[], char* key)
{
    int index = hash(key);
    sllnode* ptr = HashTable[index];
    // проверка первого элемента списка
    if (ptr->val == key)
    {
        return true;
    }
    // цикл по элементам
    while (ptr->next != NULL)
    {
        if (ptr->val == key)
        {
            return true;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    // проверка последнего элемента списка
    if (ptr->val == key)
    {
        return true;
    }

    return false;
}

// выделяем память под таблицу
void create(sllnode* HashTable[])
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        HashTable[i] = malloc(sizeof(sllnode));

        // проверяем на ошибку
        if (HashTable[i] == NULL)
        {
            printf("Error1\n");
            exit(1);
        }
        HashTable[i]->next = NULL;
    }
}