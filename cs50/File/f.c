#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define SIZE 45

typedef struct sllist
{
    char* val;
    struct sllist* next;
}
sllnode;
sllnode* insert (sllnode* head, char* value);
sllnode* create(char* value);
void showlist (sllnode* head);



int main (void)
{
    FILE * pFile;
    pFile = fopen ("text.txt","r");
    sllnode S;
    int snt = fscanf (pFile, "%s", S.val);
    printf("%s\n", S.val);
    snt = fscanf (pFile, "%s", S.val);
    printf("%s\n", S.val);
    // fscanf (pFile, "%s", buffer);
    // sllnode* new = create(buffer);
    // printf("%s\n", new->val);

    // free(buffer);
    // free(new);
}


sllnode* insert (sllnode* head, char* value)
{
    //выделили память под переменную типа sllnode
    sllnode* ptr = malloc(sizeof(sllnode));
    //проверили на ошибки
    if (ptr == NULL)
    {
        return NULL;
    }
    //заполнили новый элемент данными
    ptr->val = value;
    ptr->next = head;
    //вернули указатель на первый элемент списка
    return ptr;
}

sllnode* create(char* value)
{
    //выделили память под переменную типа sllnode
    sllnode* ptr = malloc(sizeof(sllnode));
    //проверили на ошибки
    if (ptr == NULL)
    {
        return NULL;
    }
    ptr->val = value;
    ptr->next = NULL;
    return ptr;
}

void showlist (sllnode* head)
{
    if (head != NULL)
    {
        printf("%s ", head->val);
        showlist(head->next);
    }
    else
    {
        printf("\n");
    }

}