#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;  //size of array;
    int top;   //store index of latest element if array is null then top = -1
    char *arr; //our dynamic array
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
void push(struct stack *s, char data)
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

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        // printf("stack is empty\n");
        return -1;
    }
    else
    {
        char val = s->arr[s->top];
        s->top = s->top - 1;

        return val;
    }
}
char stackTop(struct stack *s)
{

    return s->arr[s->top];
}
int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    else if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int multiparen(char *exp)
{
    struct stack *sp;
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char pp;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pp = pop(sp);
            //Here we are checking that if popped element and Current element of expression are not same then we will not further
            if (!match(pp, exp[i]))
            {
                return 0;
            }
        }
    }
    //Here we check that in last if anything is left in stack then exp is not balanced else it is balanced 
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char const *argv[])

{

    char *exp = "{(7-3-2)+[8+(99-11)]}";
    if (multiparen(exp))
    {
        printf("parethesis are Balanced");
    }
    else
    {
        printf("parethesis are not Balanced");
    }

    return 0;
}
