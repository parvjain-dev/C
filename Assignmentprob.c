#include <stdio.h>

int n_of_person;
void printarray(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//permutation function
void permutation(int arr[3], int start, int end , int cost[3][3], int *mincost)
{
    int sum;
    
    if(start==end)
    {
          sum=0;
          int i;
        // printarray(arr, end+1);
        for ( i = 0; i < n_of_person; i++)
        {
             sum+= cost[arr[i]-1][i]; 
        }
      
        if (sum<*mincost)
             {
                 *mincost=sum;
                 for (int l = 0; l < 3; l++)
                 {
                     printf("%d ", arr[l]);
                 }
             }
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap((arr+i), (arr+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start+1, end,cost,mincost);
        swap((arr+i), (arr+start));
    }
}

int main()
{
    //taking input to the array
    // int size;
    // int arr[3] = 
    // printf("Enter the size of array\n");
    // scanf("%d",&size);
    // int i;
    // int arr[size];
    // for(i=0;i<size;i++)
    //     scanf("%d",&arr[i]);
    // //calling permutation function
     int cost[3][3] ={
          {2,6,13},
          {1,3,2},
          {3,1,5}
     };
       int sum =0;
     for (int i = 0; i < 3; i++)
     {
         for (int j = 0; j < 3; j++)
         {
            if (i==j)
            {
                sum+=cost[i][j];
            }
         }
     }
     int mincost =sum;
     int arr[3] = {1,2,3};
int size = 3;
    
    printf("Enter number of person :\n");
  scanf("%d",&n_of_person);
permutation(arr, 0, size-1 ,cost,&mincost);
printf("%d", mincost);
    return 0;
}