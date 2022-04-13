#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void display( int * ptr[], int n){
    for (size_t i = 0; i < n; i++)
    {
        printf("%d\n",*ptr[i]);
    }
    
}
 
 void rotate(int * ptr[] , int n){
     for (int i = 0; i < n; i++)
     {
         int temp = *ptr[n];
         *ptr[i] = *ptr[i+1];
     }
     printf("%d\n");

 }
int main(){
int n=5;
int arr[n];
int * ptr[n];

printf("Enter the value of array : \n ");
for (int i = 0; i < n; i++)
{
    scanf("%d",&arr[i]);
}

for (int  i = 0; i < n; i++)
{
    ptr[i]= &arr[i];
}
display(ptr,n);
printf("--------\n");
rotate(ptr,n);
printf("--------\n");
display(ptr,n);
return 0;
}
