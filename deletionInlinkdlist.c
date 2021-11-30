#include<stdio.h>
#include <stdlib.h>
//WHEN WE DELETE A NODE THEN WE FREE THAT MEMORY BECAUSE THAT IS DYNAMIC MEMORY
struct Node
{
    int data;
    struct Node * next;

};

 void displaylist( struct Node * ptr){
      while (ptr!=NULL)
      {
          printf("%d\n", ptr->data);
          ptr = ptr->next ;
      }
      
 }

 struct Node * deletionAtfirst(struct Node * head){
     struct Node * ptr = head;  //we created a pointer which points to a head of our first node
    
     head = head -> next;  // Now our head pointer (which is pointing to our first node ) is now pointing to nex t Node(first)
     free(ptr);  //here are free the memory of our deleted memory
    //  return head;


 }

 struct Node * deleteInbetween(struct Node * head , int index){
           struct Node * p = head;
           int i =0;
           while (i==index-1)
           {
               p=p-> next;
               i++  ;
           }
        struct Node * q = p->next;
        p->next= q->next;
        free(q);
           return head;
 }

int main(int argc, char const *argv[])

{
    struct Node * head = (struct Node *) malloc (sizeof(struct Node));
    struct Node * first = (struct Node *) malloc (sizeof(struct Node));
    struct Node * second = (struct Node *) malloc (sizeof(struct Node));
   
    struct Node * third = (struct Node *) malloc (sizeof(struct Node));
        

   head ->data= 231;
   head-> next= first;

   first -> data = 345;
   first -> next = second;

   second -> data = 77;
   second ->next = third;

   third -> data = 11;
   third -> next = NULL;

   displaylist(head);

   printf(" \n--------- \n");

//    deletionAtfirst(head);

  deleteInbetween(head,4);

   displaylist(head);
    return 0;
}
