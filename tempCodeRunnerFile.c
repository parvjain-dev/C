#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void copy(char s1[100], char s2[100], int rec, int n){
if(rec==n){
return;
}
else{
s2[rec] = s1[rec];
copy(s1, s2, ++rec, n);
}
}
int main(){

char s[100];
printf("Enter the string\n");
scanf("%s", s);
char s_copy[100];
int n = strlen(s);
copy(s, s_copy, 0, n);
printf("Copied string: %s\n", s_copy);
return 0;
}