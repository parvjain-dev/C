#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *top)
{
    while (top != NULL)
    {
        printf("Elements are : %d\n", top->data);
        top = top->next;
    }
}
int isEmpty(struct Node *top)
{
    if (top == NULL) //means top ka data is null hai mtlb kuch nhi
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
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    //MEANS WE ARE NOT ABLE TO ALLOCATE MEMORY DYNAMICALLY
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("stack overflow\n");
    }
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = x;
        p->next = top;
        top = p;
        return top;
    }
}

//Kind of deletion of node
int pop(struct Node **top)
{

    if (isEmpty(*top))
    {
        printf("Stack underflow");
    }
    else
    {
        //P is the pointer which points toward top
        struct Node *p = *top;
        *top = (*top)->next;
        int x = p->data;
        free(p);
        return x;
    }
}

int peek(struct Node *top, int pos)
{
    //It is a pointer which is pointng to top
    struct Node *ptr = top;
    //this loop will run position -1 because when poition = 1 , 2, 3 // n times run will be = 0,1,2 and one contion is we are checking NULL of our pointer
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        //this is our poisition element
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int stack_Top(struct Node *top)
{
    if (isEmpty(top))
    {
        return -1;
    }
    else
    {
        struct Node *ptr = top;

        return ptr->data;
    }
}
int stack_Bottom(struct Node *top)
{
    if (isEmpty(top))
    {
        return -1;
    }
    else
    {
        struct Node *ptr = top;
        int i = 0;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            i++;
        }

        return ptr->data;
    }
}
int main()
{
    struct Node *top = NULL; //initially empty linkdelist
    top = push(top, 34);
    top = push(top, 12);
    top = push(top, 354);
    top = push(top, 384);
    //     traversal(top);
    //     printf("---------\n");
    //     int p1 =pop(&top);
    //     printf("popped successfull %d\n", p1);
    //    int p2=  pop(&top);
    //     printf("popped successfull %d\n", p2);
    traversal(top);

    int pk = peek(top, 3);
    printf("Peeked element is : %d\n", pk);

    int topelement = stack_Top(top);
    printf("Top Element is : %d\n", topelement);

    int bottomelement = stack_Bottom(top);
    printf("Bottom Element is : %d\n", bottomelement);
}