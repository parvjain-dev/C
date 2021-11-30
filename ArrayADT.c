#include<stdio.h>
#include<stdlib.h>
struct myarray
{
	//total size of array 
	int total_size;
	//used size from the total size
	int used_size;
	//uss array ke phele element ko point karega
   int *ptr;
    
};
 //this method is taking abstract datatype
 //this STRUCT MYARRAY *A is a structure pointer which will take the address of structure array
 void createArray(struct myarray * a  , int tsize , int usize){
    (*a).total_size = tsize;
    (*a).used_size = usize;
	
	//we are taking dynamic array in heap with the help of malloc of tsize (int *) this is a type cast 
	//and struct ptr is pointing the first element address of below array
	(*a).ptr  = (int * ) malloc(tsize*sizeof(int));
 }
void show(struct myarray *a){
	//here a is a struct myaaray pointer which will point till used size 
	for (int i = 0; i < a->used_size; i++)
	{
	printf("%d\n", (a->ptr)[i]);
	} 
}
//this below method is for set value on our dynamic array
void setval(struct myarray *a){
	int n ;
	for (int i = 0; i < a->used_size; i++)
	{
		printf("Enter element %d", i);
	scanf("%d", &n);
	(a->ptr)[i] =n;
	}
}
int main(){ 
	//below code is like object of myarray struct
   struct myarray marks;
    //&marks --> *a is the point so we point the address of marks array 
   //100 --> total size
   //20 --> we are using size
   createArray(&marks , 10 , 2);
   printf("We are running set val now\n");
setval(&marks);

   printf("We are running show  now\n");
show(&marks);

return 0;
}