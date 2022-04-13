#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *sp)
{
    if (sp->top = sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *sp, int data)
{
    if (!isFull(sp))
    {
        sp->top++;
        sp->arr[sp->top] = data;
    }
    else
    {
        printf("stack over flow\n");
    }
}
int pop(struct stack *sp)
{
    if (!isEmpty(sp))
    {
        int val = sp->arr[sp->top];
        sp->top =sp->top-1;
        return val;
    }
    else
    {
        printf("stack undeerflow\n");
        return -1;
    }
}

int isPrece(char ch)
{
    if (ch == '/' || ch == '*')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOper(char ch)
{
    if (ch == '/' || ch == '*' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int stacktop(struct stack *s)
{
    return s->arr[s->top];
}
char *intopost(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top - 1;

    //store the question or infix
    sp->arr = (char *)malloc(sp->size * sizeof(int));
    char *post = (char *)malloc(strlen(infix + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOper(infix[i]))
        {
            post[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (isPrece(infix[i]) > isPrece(stacktop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                post[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp))
    {
        post[j] = pop(sp);
        j++;
    }
    post[j] = '\0';

    return post;
}
int main(int argc, char const *argv[])
{
    char *infix = "a-b+t/6";
    printf("postfix is %s", intopost(infix));
    return 0;
}
