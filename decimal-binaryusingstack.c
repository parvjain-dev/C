#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int *arr;
    int size;
};

void display(struct stack *s)
{
     printf("Element is:");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d", s->arr[i]);
    }
}
int isempty(struct stack *s)
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
        printf("stack overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct stack *s)
{
    if (isempty(s))
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        int val = s->top;
        s->top--;

        return val;
    }
}

void dectobin(int num)
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack *));
    s1->size = 10;
    s1->top = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(struct stack));
    while (num != 0)
    {
        push(s1, num % 2);
        num = num / 2;
    }
    display(s1);
}
int main(int argc, char const *argv[])
{
    //struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    //s->size = 8;
    //s->top = -1;
    //s->arr = (int *)malloc(s->size * sizeof(struct stack));

    int n;
    printf("Enter the element you want to convert :");
    scanf("%d", &n);
    dectobin(n);

    return 0;
}
