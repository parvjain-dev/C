#include <stdio.h>
#include <stdlib.h>
//WHEN WE DELETE A NODE THEN WE FREE THAT MEMORY BECAUSE THAT IS DYNAMIC MEMORY
struct Node
{
    int data;
    struct Node *next;
};

void displaylist(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deletionAtfirst(struct Node *head)
{
    struct Node *ptr = head; //we created a pointer which points to a head of our first node
    head = head->next; // Now our head pointer (which is pointing to our first node ) is now pointing to nex t Node(first)
    free(ptr);         //here are free the memory of our deleted memory
    return head;
}

struct Node *deleteInbetween(struct Node *head, int index)
{
    //p is pointing to  first node
    //q is pointing to  just after first Node
    //Our approach will be like both out p and q traverse to our delete node means after traversing our q points to delete node and p pointing delete-1 node
    //after traversing done then we will make p->next to q->next(which is after deletion node)
    //now we will free our memory
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteLastNode(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        ptr = ptr->next;
    }

    ptr->next = NULL;
    free(q);
    return head;
}

struct Node *deleteNodeatvalue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    //Here we are checking two things first this loop will run until our value will not get and second thing iff the value is not there in linked list then there is no use of it we put NULL condition also
    while (q->data != value && q->next != NULL)
    {
        ptr = ptr->next; 
        q = q->next;
    }

    //Now for deletion we will delete only if we have value for that value or not
    if (q->data == value)
    {
        ptr->next = q->next;
        free(q);
    }else{
        printf("Sorry Value is not there");
    }

    return head;
}

int main(int argc, char const *argv[])

{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));

    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 231;
    head->next = first;

    first->data = 345;
    first->next = second;

    second->data = 77;
    second->next = third;

    third->data = 11;
    third->next = NULL;

    displaylist(head);

    printf(" \n--------- \n");

    //    head=   deletionAtfirst(head);

    //   head=deleteInbetween(head,2);

    //   head = deleteLastNode(head);

    head = deleteNodeatvalue(head, 345);
    displaylist(head);
    return 0;
}
