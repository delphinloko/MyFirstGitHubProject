#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
//создали структуру sllnode включающую в себя
// val типа int
// и указатель next
typedef struct sllist
{
    int val;
    struct sllist* next;
}
sllnode;

int main(void)
{
    //создали переменную list типа sllnode и задали её значения
    sllnode list;
    list.val = 5;
    list.next = NULL;
    printf("%i\n", list.val);
    //создали указатель на структуру list1 типа sllnode
    //запросили под неё память и задали значения
    sllnode* list1 = malloc(sizeof(sllnode));
    //проверили на ошибки
    if (list1 == NULL)
    {
        return 1;
    }
    list1->val = 7;
    list1->next = NULL;
    printf("%i\n", list1->val);
    //освободили место
    free(list1);
}
