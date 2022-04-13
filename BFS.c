#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is overflowing\n");
    }
    else
    {

        q->rear++;
        q->arr[q->rear] = data;
        // printf("Enqueued Element is %d \n", data);
    }
}

int deQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is underflowing\n");
    }
    else
    {
        q->front++;
        int a = q->arr[q->front];
        return a;
        //    printf("Dequeued element is %d : ",a);
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 400;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
int size;
printf("Enter the size of the Adjacency Matrix : ");
scanf("%d",&size);
// adjancency matrix refer to cwh graph
int adj[size][size];
for (int k = 0; k < size; k++)
{
    for (int l = 0; l < size; l++)
    {
        scanf("%d" , &adj[k][l]);
    }
    
}

    // int adj[7][7] = {
    //     //   0,1,2,3,4,5,6
    //     {0, 1, 1, 1, 0, 0, 0}, // 0
    //     {1, 0, 0, 1, 0, 0, 0}, // 1
    //     {1, 0, 0, 1, 1, 0, 0}, // 2
    //     {1, 1, 1, 0, 1, 0, 0}, // 3
    //     {0, 0, 1, 1, 0, 1, 1}, // 4
    //     {0, 0, 0, 0, 0, 1, 0}, // 5
    //     {0, 0, 0, 0, 0, 1, 0}  // 6
    // };
    // BFS implementation
    int node;
     int i ; // from which node you want to start
printf("\n Enter the node from where you want to start :");
   scanf("%d",&i);

    int visited[size]; // no of nodes
    // int visited[4]= {0}; // no of nodes
     for (int k = 0; k < size-1; k++)
     {
         visited[k] = 0;
     }
     
    
    printf("%d ", i);
    visited[i] = 1; // noticing visited node should be 1
    enqueue(q, i);  // Enqueueing i for exploration

    while (!isEmpty(q)) // Till our queue become not empty
    {
        //below we are saving node from queue and performng ops on it
        int node = deQueue(q);
        for (int j = 0; j < size; j++)
        {
            if (adj[node][j] == 1 && visited[j] == 0) //
            // adj[node][j] means particular number in 2d matrix and j is for node means row by row now first condtition we are checking about connection of the node to node and in second condtion we are checking about visited or not both condition should true 
            {
               printf("%d " , j);
               visited[j] =1;
               enqueue(q,j) ; // for exploration
            }
        }
    }


         
    return 0;
}
