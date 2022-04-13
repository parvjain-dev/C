#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node* next;
}NODE;
void Display(NODE *h)
{
NODE *p = h->next;
while(p != h)
{
printf("%d ", p->data);
p = p->next;
}
printf("\n");
}
NODE *getNode()
{
return ((NODE*)calloc(1, sizeof(NODE)));
}
void insert(NODE *h, int element)
{
NODE *p = h;
while(p->next!=h)
p = p->next;
NODE *t;
t = getNode();
p->next = t;
t->data = element;
t->next = h;
}
int main()
{
printf("\nParv Jain , 200905316\n");
NODE h1, h2;
h1.data = h2.data = 0;
h1.next = &h1;
h2.next = &h2;
int n, i, element;
printf("\nEnter Size of List 1 : ");
scanf("%d", &n);
printf("Enter the elements : ");
for(i = 0; i < n; i++)
{
scanf("%d", &element);
insert(&h1, element);
}
printf("\nEnter Size of List 2 : ");
scanf("%d", &n);
printf("Enter the elements : ");
for(i = 0; i < n; i++)
{
scanf("%d", &element);
insert(&h2, element);
}
NODE un, in;
un.data = in.data = 0;
un.next = &un;
in.next = &in;
NODE *p1, *p2;
p1 = h1.next;
while(p1 != &h1)
{
insert(&un, p1->data);
p1 = p1->next;
}
int flag = 1;
p2 = h2.next;
while(p2 != &h2)
{
flag = 1;
p1 = h1.next;
while(p1 != &h1)
{
if(p1->data == p2->data)
{
flag = 0;
break;
}
p1 = p1->next;
}
if(flag)
insert(&un, p2->data);
if(!flag)
insert(&in, p2->data);
p2 = p2->next;
}
printf("\nUnion of both lists is : ");
Display(&un);
printf("\nIntersection of both lists is : ");
Display(&in);
printf("\n");
return 0;
}