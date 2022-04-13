// stack = LIFO Last In First Out
// queue = FIFO First in first out

// ADT Queue
// DATA : 1. Storage 2. insertion end 3. deletion end
// Methods : 1. enqueue   (come from last) 2. dequeue    (remove from first)  3. first value 4. last value 5. queuepeek 6. isEmpty 7. isFull
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front; // hold first element in queue
    int rear;  // hold last elements in queue
    int *arr;  // For dynamic memory for array
};

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))

    {
        printf("Queue is overflowing\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
        printf("Enqued element: %d\n", val);
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue Underflowing");
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 5;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 14);
    //   q->arr[0] = 12;
    //   q->rear= q->rear+1;
    //   q->arr[1] =14;
    //   q->rear = q->rear+1;
    //  // q->arr[2] = 45;
    //   //q->rear= q->rear+1;
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    enqueue(q, 45);
    enqueue(q, 45);
    enqueue(q, 45);

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    if (isFull(q))
    {
        printf("Queue is full\n");
    }
    //   if (isFull(q))
    //   {
    //       printf("Queue is Full\n");
    //   }
    //   else{
    //       printf("Queue is not full\n");
    //   }
    return 0;
}
