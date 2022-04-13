// circular increment i = (i+1)%size
//front always empty in circular queue
#include <stdlib.h>
#include <stdio.h>

struct queue
{
    int front;
    int rear;
    int *arr;
    int size;
};

int isFull(struct queue *q)
{

    //HERE ANALOGY IS LIKE TWO BOXES ARE CLOSE TOGETHER MEANS NOTHING IS THRE B/W THOSE BOXES SO REAR POINTS TO FIRST BOX ADN FRONT POINTS TO SECOND BOX SO, IF WE INCRMENT REAR IF IT BECOME EQUALS TO FIRST THEN IT IS CALLED FULL CONDITION
    if ((q->rear + 1) % q->size == q->front)
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
    if (q->rear == q->front)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
        printf("Enqueued value is %d\n", val);
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is underflowing\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        a = q->arr[q->front];
    }
    return a;
}

int main(int argc, char const *argv[])
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 4;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1);
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
    return 0;
}
