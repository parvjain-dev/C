#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *head)
{
    struct Node *p = head;

    //Here we do this beause p is already at head so, it exit loop without go into in so, we give start so we use do while loop for this

    do
    {
        printf("%d\n", p->data);
        p = p->next;
    } while (p != head);
}

struct Node *insertAt_first(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;

    do
    {
        p = p->next;
    } while (p->next != head); //our last node which is pointing to head
                               //At this point our p is at last Node

    ptr->next = head;
    p->next = ptr;
    head = ptr;
    return head;
}

struct Node *insertAtLast(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    do
    {
        p = p->next;
    } while (p->next != head);

    p->next = ptr;
    ptr->next = head;
    return head;
}
//If head is empty --> head == NULL

struct Node * insertInbetween (struct Node * head , int index , int data){
    struct Node * ptr = (struct Node *) malloc (sizeof(struct Node) );
    ptr->data = data;
    struct Node * p = head;
    int i =0;
   while (i!=index-1)
   {
       p= p->next;
       i++;
   }
   
    p->next = ptr;
    ptr-> next = p->next;
    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 90;
    head->next = first;

    first->data = 100;
    first->next = second;

    second->data = 110;
    second->next = third;

    third->data = 120;
    third->next = head;

    printf("Linkedlist Without any insertion\n");

    traverse(head); 

//     printf("Linkedlist after insertion at first\n");

//    head = insertAt_first(head, 130);

//     traverse(head);

//     printf("Insertion at end\n");
//     head = insertAtLast(head, 5);
//     traverse(head);
   printf("Linkedlist after insertion in between");
    head = insertInbetween(head,2 , 15);
    traverse(head);
    return 0;
}
