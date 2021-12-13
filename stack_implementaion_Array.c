#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size; //size of array;
    int top;  //store index of latest element if array is null then top = -1
    int *arr; //our dynamic array
};

void traverse(struct stack *s)
{

    printf("The elements in the stack is :");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->arr[i]);
    }
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; //means true
    }
    else
    {
        return 0;
    }
}

int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *s, int data)
{
    if (isfull(s))
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        // printf("stack is empty\n");
        return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top = s->top - 1;

        return val;
    }
}
int main(int argc, char const *argv[])

{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack)); //(struct stack *) it means our return type is a pointer of struct stack by default it is void    this is our actual stack whose address is stored by s

    printf("Enter the size of array \n");
    int n;
    int loopcount = 1;
    // scanf("%d", n);
    s->size = 8;

    s->top = -1;

    s->arr = (int *)malloc(s->size * sizeof(int)); //s-> size represent how much space we need then (int) represent what type data will gonna come

    //Now we no need this because we are using push and pop
    //   s->arr[0] = 7;
    //     s->top++;

    while (loopcount)
    {
        int po;
        int pu;
        printf("enter your choice:\n1.For push\n2.For Pop\n3.To display the stack\n4.To check stack is empty or Not\n5.To check stack is full or not\n6.For exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Element you want to push\n");
            scanf("%d", &pu);
            push(s, pu);
            printf("Push successfull\n");
            break;
        case 2:
            po = pop(s);
            printf("Popped out valus is %d\n", po);
            break;
        case 3:
            traverse(s);
        case 4:
            if (isEmpty(s))
            {
                printf("The stack is empty\n");
            }
            else
            {
                printf("The stack is not empty\n");
            }
            break;
        case 5:
            if (isfull(s))
            {
                printf("The stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }

            break;
        case 6:
            loopcount = 0;
            break;
        default:
            break;
        }
    }

    return 0;
}
