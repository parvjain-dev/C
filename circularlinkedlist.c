#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node * next;

};

void traverse(struct Node * ptr){
    
    while ( ptr != head )
    {
      printf("%d\n", ptr->data);
      ptr= ptr->next;
    }
    

}

int main(int argc, char const *argv[])
{
    struct Node * head = (struct Node *) malloc (sizeof(struct Node));
    struct Node * first = (struct Node *) malloc (sizeof(struct Node));
    struct Node * second = (struct Node *) malloc (sizeof(struct Node));
    struct Node * third = (struct Node *) malloc (sizeof(struct Node));
   
   head -> data = 90;
   head -> next = first;

   first -> data = 100;
   first ->next = second;

   second -> data =110;
   second ->next = third;

   third -> data =120;
   third ->next = head;
    return 0;

traverse(head);
}
