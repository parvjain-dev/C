#include <stdio.h>
#include <stdlib.h>

int smallest(int *arr, int n)
{
    int small = *arr;
    for (int i = 1; i < n; i++)
    {
        if (*(++arr)<small)
        {
            small = *arr;
        }
    }
    return small;
}

int main(int argc, char const *argv[])

{
    int n = 4;
    int * arr = (int *)malloc(n*sizeof(int));
    arr[0]= 3;
    arr[1]=10;
    arr[2]=2;
    arr[3]=90;
    int small = smallest(arr , n);
    printf("%d", small);
    return 0;
}
