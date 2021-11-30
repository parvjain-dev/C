#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;

    //struct node type ka pointer hai jo ki next address ko point karega
    struct Node *next;
};

//this ptr willl point the head node
void linkedlisttraversal(struct Node *ptr) 
{
    while (ptr != NULL)
    { 
        //phele data pe fir next jha pe node hai jo ki next data se link hai
        printf("Element: %d\n", ptr->data);
        ptr =ptr->next;
    }
}
int main(int argc, char const *argv[])

{
    ///Allocate memory in heap
    //These are nodes which points next data

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    struct Node *second = (struct Node *)malloc(sizeof(struct Node));

    struct Node *thrid = (struct Node *)malloc(sizeof(struct Node));

    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    //Link first and second node
    head->data = 7;
    head->next = second;

    //Link second and third node
    second->data = 11;
    second->next = thrid;

    //link third and fourth
    thrid->data = 78;
    thrid->next = fourth;

    //terminate fourth
    //output will be some value  
    fourth->data = (int)"parvjain";
    fourth->next = NULL;

    linkedlisttraversal(head);
    return 0;
}
