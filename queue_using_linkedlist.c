#include <stdlib.h>
#include <stdio.h>

//TAKE QUEUE --> NODE
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Queues element are %d\n", ptr->data);
        ptr = ptr->next;
    }
}
//OUR FRONT AND REAR ARE GLOBALLY AVAILABLE SO, WE DONT NEED TO GIVE FRONT AND REAR IN ARGUEMENT
//IT is like insertion at last
// void enqueue(struct Node * front, struct Node * rear,int val){
void enqueue(int val)  
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    //means we are not able to make new node may be our mewmory is full so queue is full
    if (newNode == NULL)
    {
        printf("QUEUE IS FULL\n");
    }
    else
    {
        newNode->data = val;
        newNode->next = NULL;

        //suppose our  initially our front is also null and rear is also NUll so, when we insert our first node then our front and rear both points to then first node
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            //it means that we are just making connection
            rear->next = newNode;
            //now move rear to new node
            rear = newNode;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = front;
    if (front == NULL)
    {
        printf("QUEUE IS EMPTY");
    }
    else
    {
        front = front->next;
        val = ptr->data;
        return val;
    }
}

int main()
{

    //  linkedlisttraversal(front);
    int d = dequeue();
    // printf("%d\n", d);
    printf("------\n");
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    enqueue(16);
    enqueue(17);
    linkedlisttraversal(front);
    printf("------\n");
    int d1 = dequeue();
    printf("Dequeued Value is %d\n", d1);
    printf("------\n");
    linkedlisttraversal(front);
    return 0;
}
