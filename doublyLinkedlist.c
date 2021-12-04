#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * prev;
    struct Node * next;
};


void traverse(struct Node * head){
    struct Node * p = head;
    while (p->next!= NULL)
    {
        printf("%d\n" , p->data);
        p=p->next;
        
    }
    printf("%d\n" , p->data);
}

void reversetraversal(struct Node * last){
    struct Node * p = last;
    while (p->prev!= NULL)
    {
        printf("%d\n" , p->data);
        p=p->prev;
        
    }
    printf("%d\n" , p->data);
}
int main(int argc, char const *argv[])

{
    struct Node * head;
    struct Node * first;
    struct Node * second;
    struct Node * third;

    head = (struct Node *) malloc(sizeof(struct Node *));
    first = (struct Node *) malloc(sizeof(struct Node *));
    second= (struct Node *) malloc(sizeof(struct Node *));
    third= (struct Node *) malloc(sizeof(struct Node *));


    head ->prev = NULL;
    head->data = 10;
    head->next=first;

    first ->prev = head;
    first ->data = 20;
    first -> next = second;

    second ->prev = first;
    second -> data = 30;
    second -> next = third;

    third->prev = second;
    third->data = 40;
    third -> next = NULL;


    printf("Linkedlist in forward\n");

    traverse(head);

    printf("linkedlist traverse in backward\n");
    reversetraversal(third);
    return 0;
}
