#include<stdio.h>


int indexinsertion(int arr[] , int size , int element , int capacity , int index){
      //this if block is for if capacity is full so we cannot do anything
    if (size>=capacity)
    {
      return -1;
    }

    //now just shifting to index+1
    for (int  i = size-1; i >= index; i--)
    {
      arr[i+1] = arr[i];
    }
    
    //Now elements are shifted now we will insert our element
    arr[index] = element;


    return 1;
}


void display(int arr[] , int n){
    //traversal
      for (int  i = 0; i < n; i++)
      {
          printf("%d\n", arr[i]);
      }
      
}


int main(int argc, char const *argv[])

{
  
     int arr[50] ={1,2,6,7} ;

      


       int size , element , index;
       printf("Enter size of array but please enter size less then 50:");
     
       scanf("%d" , &size);
       
       

       printf("\nEnter element which you want to insert:");
       scanf("%d" ,&element);
       
       printf("\nEnter the index on which you want to insert:");
       scanf("%d" ,&index);

     display(arr , size);
      
      printf("\n");

      //here size is like how much space we are using of array
      //element is which element we want to insert
      //index is on which index you want to insert 
      //here 50 is capacity
     int flag =indexinsertion(arr,size,element,50,index); 
      //after insertion size will also increase
     size+=1;
       if (flag ==1)
       {
         display(arr , size);
       }else
       {
         printf("insertion failed");
       }
       
        


    

 

    return 0;
}
 