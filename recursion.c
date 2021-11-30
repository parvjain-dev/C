
#include <stdio.h>

int sumofnumber(int n){
    if (n<10)
    {
      return n; 
    }
    else{
        //%10 give  last number and /10 give remaining number
      return n%10 + sumofnumber(n/10);
    }
    
}

int powerN(int a , int n){
    if (n==1)
    {
        return a;
    } 
    else
    {
        return a*powerN(a , n-1);
    }
    
    
}

int main(int argc, char const *argv[])
{
    /* code */
   printf("%d\n" , sumofnumber(1269)) ;
   printf("%d" ,powerN(2,3)) ;

    return 0;
}
