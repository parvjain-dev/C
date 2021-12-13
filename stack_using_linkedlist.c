#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(struct Node *ptr)
{
    if (ptr->next == NULL)
    {
        return 1;
       // printf("Linkdlist is empty\n");
    }
    else
    {
       // printf("Linkedlist is not empty\n");
        return 0;
    }
}
int isFull(struct Node * ptr){

}

void  pop (struct Node * ptr){
    if (isEmpty(ptr))
    {
        printf("sorry  linkedlist is empty");
    }
    else{
        ptr = ptr->next;
        free(ptr);
        printf("pop successfull and popped item is : %d",ptr->data);
    }
    
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = NULL;

    traversal(head);
   // isEmpty(head);
    pop(head);
    //traversal(head);
}