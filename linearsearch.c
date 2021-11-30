#include<stdio.h>

//This search takes O(n)
 
void display(int arr[] , int size){
    for (int  i = 0; i < size; i++)
    {
        printf("%d" , arr[i]);
         printf("\n");
    }
   
}
void linearsrch(int arr[] ,int find ,int size){
     int flag =0;
    for (int  i = 0; i <= size; i++)

    {
        if (find == arr[i])
        {
            flag=1;
            printf("%d" ,i+1);
            break;
        }
        
        
    }
   if (flag ==0)
   {
       printf("Sorry number not found");
   }
   
 
    
}
int main(int argc, char const *argv[])
{
     int arr[10] = {1,3,2,53,123,1,34,12};
    //   display(arr, 5);
      
    
      int find ;
      printf("Enter a number which you want to find :");
      scanf("%d" , &find);

        int size = sizeof(arr)/sizeof(int);
     

        
         printf("the element %d was found at index ",find);
linearsrch(arr, find , size);
    return 0;
}
