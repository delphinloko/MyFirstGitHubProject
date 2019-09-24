/****************************************************************************
 
* stacks.c
*
 
* Provotorov Daniil
* provotorov.d.i@gmail.com
*
 
* Demonstrates stack.
*
 
***************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

typedef struct _stack
{
    char* val;
    struct _stack* next;
}
stack;

// глобальные переменные
stack* top;

// прототипы функций
void push (char* word);
char* pop();

int main(void)
{
    push("Aki");push("Koki");push("Akiu");push("123");push("hypi");printf("%s\n", top->val);
    char* first = pop();char* second = pop();
    printf("%s\n", first);printf("%s\n", second);printf("%s\n", top->val);
}

// возвращаем верхний элемент стека
char* pop()
{
    stack* ptr = top;
    if (ptr->next == NULL)
    {
        char* word = ptr->val;
        free(ptr);
        return word;
    }
    else
    {
        char* word = ptr->val;
        ptr = ptr->next;
        free(top);
        top = ptr;
        return word;
    }
}

// вставляем элемент в стек
void push (char* word)
{
    stack* ptr = malloc(sizeof(stack));
    if (ptr == NULL)
    {
        exit(1);
    }
    ptr->val = word;
    ptr->next = top;
    top = ptr;
}
// создали стек
// void create()
// {
//     stack* ptr = malloc(sizeof(queue));
//     ptr->val = NULL;
//     ptr->next = NULL;
//     top = ptr;
// }