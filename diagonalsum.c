#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
     int cost[3][3] ={
          {12,6,10},
          {1,2,2},
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
     printf("%d",sum);
    return 0;
}
