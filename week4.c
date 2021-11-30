#include <stdio.h>
#include<stdlib.h>
#define SIZE 20
typedef struct{
 int data[SIZE];
 int top1;
 int top2;
}stack;
void initializeStack(stack *s){
 s->top1 = -1;
 s->top2 = SIZE;
}
void pushStackOne(stack *s, int i){
 if(s->top1 == s->top2 - 1){
 printf("Stack Overflow.\n");
 return;
 }
 s->data[++s->top1] = i;
}
void pushStackTwo(stack *s, int i){
 if(s->top1 == s->top2 - 1){
 printf("Stack Overflow.\n");
 return;
 }
 s->data[--s->top2] = i;
}
void popStackOne(stack *s){
 if(s->top1 == -1){
 printf("Stack Underflow.\n");
 return;
 }
 printf("%d popped from Stack 1.\n", s->data[s->top1--]);
}
void popStackTwo(stack *s){
 if(s->top2 == SIZE){
 printf("Stack Underflow.\n");
 return;
 }
 printf("%d popped from Stack 2.\n", s->data[s->top2++]);
}
void printStackOne(stack *s){
 printf("Stack 1 : ");
 for(int i = s->top1; i >= 0; i--){
 printf("%d\t", s->data[i]);
 }
 printf("\n");
}
void printStackTwo(stack *s){
 printf("Stack 2 : ");
 for(int i = s->top2; i < SIZE; i++){
 printf("%d\t", s->data[i]);
 }
 printf("\n");
}
int main()
{
 printf("Parv Jain 200905316\n");
 stack *s;
 s = (stack*)malloc(sizeof(s));
 initializeStack(s);
 int choice = 0, ele = 0;
 printf("MENU\nEnter 1 to Push to Stack 1\nEnter 2 to Push to Stack 2\nEnter 3 to Pop from Stack 1\nEnter 4 to Pop from Stack 2\nEnter 5 to Print Stack 1\nEnter 6 to Print Stack 2\nEnter 7 to Exit\n");
 while(choice < 7){
 printf("Enter choice : ");
 scanf("%d", &choice);
 if(choice == 1){
 printf("Enter element to push into Stack 1 : ");
 scanf("%d", &ele);
 pushStackOne(s, ele);
 }
 else if(choice == 2){
 printf("Enter element to push into Stack 2 : ");
 scanf("%d", &ele);
 pushStackTwo(s, ele);
 }
 else if(choice == 3)
 popStackOne(s);
 else if(choice == 4)
 popStackTwo(s);
 else if(choice == 5)
 printStackOne(s);
 else if(choice == 6)
 printStackTwo(s);
 }
 return 0;
}
