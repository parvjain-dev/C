#include<stdio.h>

void display(int arr[] , int size){
    for (int  i = 0; i < size; i++)
    {
        printf("%d" , arr[i]);
         printf("\n");
    }
   
}
void deletion(int arr[], int size,  int index){
  
    
    for (int  i = index; i <size-1; i++)
    {
       arr[i] = arr[i+1];
    }
        
    
    
}
int main(int argc, char const *argv[])
{
    int arr[50] = {12,32,32,3,1,54,3};
     int size;
      int element;
       int index;
    display(arr,size);
   
   printf("Enter the size of arr :");
  
   
    scanf("%d",&size);

   printf("Enter the index of which element  you want to delete :");
  
   scanf("%d",&index);

    deletion(arr,size,index);
    
    size-=1;

    display(arr,size);
    return 0;
}
