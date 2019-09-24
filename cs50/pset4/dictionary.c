/****************************************************************************
 
* dictionary.c
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Implements a dictionary's functionality.
*
 
***************************************************************************/


#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"
#define HASHSIZE 26

typedef struct sllist
{
    char val [45];
    struct sllist* next;
}
sllnode;
void del(sllnode* HashTable[], char* key);
unsigned int counttable (sllnode* HashTable[]);
void create(sllnode* HashTable[]);
void destroy(sllnode* HashTable[]);
unsigned int hash(const char* string);
bool find(sllnode* HashTable[], char* key);
char s [45];
sllnode* HashTable[HASHSIZE];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // �������� ������ �������� ��� ����������� ����������� �����
    char words [45];
    // ��������
    strcpy(words, word);
    // ��������� ��� ����� � ������ �������
    for (int i = 0; i < strlen(words); i++)
    {
        words[i] = tolower(words[i]);   
    }
    
    // ���������� ������ � ���-�������
    int index = hash(words);
    // ��������� ��������� �� ������ ������� ���������� ������ � �������
    sllnode* ptr = HashTable[index];
    ptr = ptr->next;
    // ���������, ���� �� ����� � ������
    while (ptr != NULL)
    {
        if (strcmp(words, ptr->val) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // ������� ������� ��� ������� � ��������� �� ������
    FILE* pFile = fopen(dictionary, "r");
    if (pFile == NULL)
    {
        printf("Could not open\n");
        unload();
        return false;
    }
    // ������� ���-�������
    create(HashTable);
    // ���������� �� ����� � ���-�������
    while (fscanf (pFile, "%s", s) != EOF)
    {
        // hash-function
        int index = (toupper (s[0]) - 'A') % HASHSIZE;
        // �������� ������
        sllnode* ptr = malloc(sizeof(sllnode));
        // �������� �� ������
        if (ptr == NULL)
        {
            printf("Error1\n");
            return false;
        }
        // ����������� �������� � ���-�������
        strcpy(ptr->val, s);
        ptr->next = HashTable[index]->next;
        HashTable[index]->next = ptr;
    }
    // ������� ����
    fclose(pFile);
    // TODO
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // ��������� ����� ��������� � �������
    return counttable (HashTable);
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // ������� �������
    destroy(HashTable);
    return true;
}

// ������� ������� � ������� ������
void destroy(sllnode* HashTable[])
{
    // ���������� �� ������� ���������� ������ � ������� ��� ��������
    for (int i = 0; i < HASHSIZE; i++)
    {
        sllnode* ptr = HashTable[i];
        while (ptr->next != NULL)
        {
            del(HashTable, ptr->next->val);
        }
    }
    // ������� ������ ���-�������
    for (int i = 0; i < HASHSIZE; i++)
    {
        free(HashTable[i]);
    }
}

// ������� �� ������� �������� �� ����� key
void del(sllnode* HashTable[], char* key)
{
    // ��������, ���������� �� �������� � �������
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

// ������� ��� ���-�������
unsigned int counttable (sllnode* HashTable[])
{
    int counter = 0;
    for (int i = 0; i < HASHSIZE; i++)
    {
        sllnode* ptr = HashTable[i];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            counter++;
        }
    }
    return counter;
}

//  hash function �� ������ ����� �����
unsigned int hash(const char* string)
{
    int hash = toupper (string[0]) - 'A';
    return hash % HASHSIZE;
}

// ���� �������� � ��� �������
bool find(sllnode* HashTable[], char* key)
{
    int index = hash(key);
    sllnode* ptr = HashTable[index];
    // �������� ������� �������� ������
    if (ptr->val == key)
    {
        return true;
    }
    // ���� �� ���������
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
    // �������� ���������� �������� ������
    if (ptr->val == key)
    {
        return true;
    }

    return false;
}

// �������� ������ ��� �������
void create(sllnode* HashTable[])
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        HashTable[i] = malloc(sizeof(sllnode));
        // ��������� �� ������
        if (HashTable[i] == NULL)
        {
            printf("Error1\n");
            exit(1);
        }
        HashTable[i]->next = NULL;
    }
}
