#include<stdio.h>

//this search takes O(logn)
int  binarysrch(int arr[] , int find , int size){
      int low , mid , high;

      low =0;
      high = size-1;
      //Keep seaching until low and high converges
      while (low<=high)
      {
           mid = (low + high) /2;
      if (arr[mid] == find)
      {
         return mid;
      }
      if (arr[mid]>find)
      {
          high = mid-1;
      }else {
          low = mid +1;
      }
      //ending search
      }
      return -1;
     
  }
int main(int argc, char const *argv[])
{

    int arr[] = {1,23,43,55,234,1223,9000};
      int find ;
      printf("Enter a number which you want to find : ");
      scanf("%d" , &find);

        int size = sizeof(arr)/sizeof(int);
        int bin =  binarysrch(arr, find , size);
         printf("the element %d was found at index %d ",find , bin);

       
    return 0;
}
