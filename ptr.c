#include<stdio.h>
int main(int argc, char const *argv[])
{
    // int a = 12;
    // int *ptr = &a;
    // printf("%d\n", a);
    // printf("%d\n",*ptr);

    int a[5] = {12,23,34,354};
    int * ptr = &a;
    printf("%d\n",*ptr);
    printf("%d\n",*ptr++);
    printf("%d\n",++*ptr);
    printf("%d\n",*++ptr);

    // int x= 15 , y = 25;
    // int* p1,  * p2;
    // p1 = &x;
    // p2=&y;
    // printf("x = %d & y= %d\n", x , y);
    // *p1= 10;
    // printf("x = %d & y= %d\n", x , y);
    // *p2 = * p1;
    // printf("x = %d & y= %d\n", x , y);
    // p1 = p2;
    // printf("x = %d & y= %d\n", x , y);
    // *p1 = 20;
    // printf("x = %d & y= %d\n", x , y);
    return 0;
}
