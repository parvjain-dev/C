#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
void traverse(struct stack *s)
{

    printf("The elements in the stack is :");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->arr[i]);
    }
}
int isempty(struct stack *ptr)
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
    if (isempty(s))
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
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
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

int isoperation(char ch){
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
char *intopo(char *infix)
{
    struct stack *sp = (struct stack *) malloc (sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    //our question or given expression wil store in this
    sp->arr =(char * )malloc(sp->size * sizeof(int));

    //store our postfix expression
    char *post = (char *)malloc(strlen(infix + 1) * sizeof(char));
    int i = 0; //infix scan left to right
    int j = 0; //postffix fill

    while (infix[i] != '\0')
    {
        if (!isoperation(infix[i]))
        {
            post[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
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
    while (!isempty(sp))
    {
        post[j] = pop(sp);
        j++;
    }
    post[j] = '\0';
    return post;
}
int main(int argc, char const *argv[])
{
   char * infix= "a-b+t/6";
   printf("postfix is %s" , intopo(infix));
    return 0;
}
