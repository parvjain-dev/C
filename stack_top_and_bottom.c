#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int *arr;
    int size;
};

void traverse(struct stack *s)
{

    printf("The elements in the stack is :");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->arr[i]);
    }
}
int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {

        return 1;
    }
    else
    {

        return 0;
    }
}
int isfull(struct stack *s)
{
    if (s->top == s->size - 1)
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
int stackTop(struct stack *s)
{

    return s->arr[s->top];
}
int stackBottom(struct stack *s)
{
    return s->arr[0];
}
int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack)); //(struct stack *) it means our return type is a pointer of struct stack by default it is void    this is our actual stack whose address is stored by s

    s->top = -1;
    s->size = 12;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 11);
    push(s, 12);
    push(s, 13);
    push(s, 14);
    int a = stackTop(s);
    printf("The Topmost value of stack is : %d\n", a);

    int b = stackBottom(s); 
    printf("The Bottommost vale os the stack is : %d\n", b);
    return 0;
} 