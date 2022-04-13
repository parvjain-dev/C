#include <stdio.h>
#include <stdlib.h>


int arr1[50];
int arr2[50];
int ptr_to_arr1_ele = -1;
int ptr_to_arr2_ele = -1;
    // adjancency matrix refer to cwh graph
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
    
  
void DFS (int i ,int size, int adj[size][size] ,int visited[size]) { //i is the node from where we want to start{
visited[i] =1;
 printf("%d ", i);
 arr1[++ptr_to_arr1_ele] = i;


for (int j = 0; j < size; j++)
{
    if (adj[i][j] ==1 && !visited[j])   {  ///Here first condtion is like where we are starting and from there only if there is any edge so it will be one only and if it is not visited also then 
      DFS(j,size,adj,visited);
    }
}

arr2[++ptr_to_arr2_ele] = i;


}
int main(int argc, char const *argv[])
    {

        printf("Enter the size of the array : \n");
        int size;
         scanf("%d", &size);
        int visited[size]; // no of nodes
        for(int i = 0; i < size;  i++){
            visited[i] =0;
        }
         int adj[size][size];
        int k,l;
        printf("Enter the adj matrix\n");
        for (int k = 0; k < size; k++)
        {
            for (int l = 0; l < size; l++)
            {
                 scanf("%d", &adj[k][l]);
            }
            
        }
        
        int start ;
        printf("Enter the start node : \n");
        scanf("%d ",&start);
        printf("DFS Traversal : ");
        DFS(start,size,adj,visited);
        printf("\nPush Order : ");
        for(int i = 0; i <= ptr_to_arr1_ele; i++) printf("%d ", arr1[i]);
        printf("\nPop Order : ");
    for(int i = 0; i <= ptr_to_arr2_ele; i++) printf("%d ", arr2[i]);
        return 0;
    }
    