#include <stdio.h>
#include <stdlib.h>

int visited[7] ={0};
int arr1[50];
int arr2[50];
int ptr_to_arr1_ele = -1;
int ptr_to_arr2_ele = -1;
    // adjancency matrix refer to cwh graph
    int adj[7][7] = {
        //   0,1,2,3,4,5,6
        {0, 1, 1, 1, 0, 0, 0}, // 0
        {1, 0, 0, 1, 0, 0, 0}, // 1
        {1, 0, 0, 1, 1, 0, 0}, // 2
        {1, 1, 1, 0, 1, 0, 0}, // 3
        {0, 0, 1, 1, 0, 1, 1}, // 4
        {0, 0, 0, 0, 0, 1, 0}, // 5
        {0, 0, 0, 0, 0, 1, 0}  // 6
    };
    
  
void DFS (int i) { //i is the node from where we want to start{
visited[i] =1;
 printf("%d ", i);
 arr1[++ptr_to_arr1_ele] = i;


for (int j = 0; j < 7; j++)
{
    if (adj[i][j] ==1 && !visited[j])   {  ///Here first condtion is like where we are starting and from there only if there is any edge so it will be one only and if it is not visited also then 
      DFS(j);
    }
}

arr2[++ptr_to_arr2_ele] = i;


}
int main(int argc, char const *argv[])
    {

    
       
        
        
        printf("DFS Traversal : ");
        DFS(4);
        printf("\nPush Order : ");
        for(int i = 0; i <= ptr_to_arr1_ele; i++) printf("%d ", arr1[i]);
        printf("\nPop Order : ");
    for(int i = 0; i <= ptr_to_arr2_ele; i++) printf("%d ", arr2[i]);
        return 0;
    }
    