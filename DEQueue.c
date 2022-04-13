//FIFO DONT FOLLOW
//INSERTION FROM REAR+FRONT
//DELETION FROM REAR+FRONT

//TWO TYPES OF DEQueue
//Restricted Input DEQueue --> Insertion from front is Not allowed
//Restricted Output DEQueue -->Deletion from Rear is not allowed

#include <stdio.h>
#include <stdlib.h>

struct DEQueue{
    int front ;
    int rear ;
    int size ;
   int * arr ;
};

int isFull(struct DEQueue * q){
    if (q->rear == q->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct DEQueue * q){
    if (q->front ==-1 && q->rear ==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}
void enqueueR(struct DEQueue * q , int val){
       if (isFull(q))
       {
          printf("Queue is overflowing\n");   
       }
       else
       {
           q->rear++;
           q->arr[q->rear] = val;
           printf("EnqueueR value is %d\n",val);
       }
}
void enqueueF(struct DEQueue * q , int val){
       if (isFull(q))
       {
          printf("Queue is overflowing\n");   
       }
       else
       {
           q->rear++;
           q->arr[q->rear] = val;
           printf("EnqueueR value is %d\n",val);
       }
}
int dequeueF(struct DEQueue * q){
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is underflowing\n");
    }
    else
    {
        q->front++;
         a=q->arr[q->front] ;
        return a;
    }
}

int main(){
     printf("LETS GO....\n");

     struct DEQueue * q = (struct DEQueue *)malloc (sizeof(struct DEQueue));
     q->size = 4;
     q->front = -1;
     q->rear = -1;
     q->arr = (int *)malloc(q->size* sizeof(int));
     enqueueR(q,1);
     enqueueR(q,12);
     enqueueR(q,4);
     enqueueR(q,678);
    //  printf("Front value is ")
    int d = dequeueF(q);
    printf("dequed element from front is %d\n",d);
    int d1 = dequeueF(q);
    printf("dequed element from front is %d\n",d1);
    return 0;

}