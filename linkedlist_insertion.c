#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};

void linkedlisttraversal(struct Node *ptr) {
        while (ptr!=NULL)
        {
            printf("%d\n" , ptr->data);
            ptr =ptr->next;
        }
        
}

//This will return new head
struct Node * insertAtfirst (struct Node *head , int data){
    //new node which we want to insert
    struct Node * ptr = (struct Node * ) malloc (sizeof(struct Node));
     ptr->next=head; //new node next will point to old head
     ptr->data =data;//new node data will be given by user
     return ptr;  //new head will return

}
struct Node * insertinbetween(struct Node * head , int data , int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
     struct Node * p =head;
     int i =0;
     //isme apn p to traverse kara rhe hai linkdlist pe se apne index tak bss
     while (i!=index-1)
     {
         p = p->next;
         i++;
     }
     //ptr = new node  
     //p = old traversing pointer

     ptr->data = data;

     //here its like new wire of new node attached to next node
     ptr->next = p->next;
     p->next=ptr;
     return head ;
}

struct Node * insertAfterNode(struct Node * head ,struct Node * prevnode , int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node *));
    ptr->data = data;

    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
}

struct Node * insertAtend(struct Node * head , int data){
    struct Node * ptr = (struct Node *) malloc (sizeof(struct Node));
    ptr->data = data;
    struct Node * p =head;
    
     while (p->next != NULL)
     {
        p = p-> next;
        
     }
     p->next=ptr;
     ptr->next = NULL;
     return head ;
}
      

int main(int argc, char const *argv[])
{
     struct Node *head = (struct Node *)malloc(sizeof(struct Node));
     struct Node *first = (struct Node *)malloc(sizeof(struct Node));
     struct Node *second = (struct Node *)malloc(sizeof(struct Node));
     struct Node *third = (struct Node *)malloc(sizeof(struct Node));


     head->data =34;
     head->next = first;

     first->data = 232;
     first->next = second;

     second -> data = 12;
     second -> next = third;

     third -> data =22;
     third -> next = NULL;

    //  linkedlisttraversal(head); 
     
    //    printf("----\n");

    //  head =insertAtfirst(head,56);

    //   linkedlisttraversal(head);

    //   printf("----\n");

    //   head = insertinbetween(head , 132 , 3);

    //   linkedlisttraversal(head);
         
        //  printf("----\n");

        //  head = insertAtend(head , 9);
        //  linkedlisttraversal(head);

        head = insertAfterNode(head,second,123);
        linkedlisttraversal(head);
         return 0;

}
