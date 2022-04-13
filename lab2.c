#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
int a[] = {2,2,3,4,5}, *p;
p =a;
++*p;
printf("%d\n" , *p);
p +=2;
printf("%d\n", *p);
 return 0;
}

