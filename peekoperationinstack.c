#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int *arr;
    int size;
};

// void traverse(struct stack *s)
// {
//   for(int i=0 ; i<s->top; i++){
//       printf("%d\n",i);
//   }
// }

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
//peek is basically used for find an element any index
int peek(struct stack * s , int i){
 if (s->top-i+1 <0)
 {
     return -1;
 }
 return s->arr[s->top -i +1];
}
int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack)); //(struct stack *) it means our return type is a pointer of struct stack by default it is void    this is our actual stack whose address is stored by s

    s->top = -1;
    s->size = 12;
    s->arr = (int *)malloc(s->size * sizeof(int));
     
     push(s,11);
     push(s,12);
     push(s,13);
     push(s,14);
     int po = pop(s);
     printf("popped value is %d\n" , po);
     int po1 = pop(s);
     printf("popped value is %d\n" , po1);
     traverse(s);
     int p =peek(s,1);
    printf("%d\n" , p);
    return 0;
}  