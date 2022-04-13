#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define MAX_VERTICES 50
#define MAX_EDGES 50

struct graph
{
   int v;  //number of vertices
   int e;  //number of edges
   int ** adjmat; //adjacency matrix
};

struct edge
{
  int source;
  int destination;
};
void rand_init(void){
    time_t t;
    srand((unsigned) time(&t));
}
struct graph * createGraph(const int numVertices)
{  
    //assert is used for comparision mainly 
     assert(numVertices>=0);
     //create an empty graph with num vertices
     int i , j;
     struct graph * G = (struct graph * ) malloc (sizeof(struct graph));
     G->v = numVertices;
     G->e =0;
     //allocate memory to each row
     G->adjmat = malloc(numVertices *sizeof(int *));
     assert(G!=NULL);
     
};

