#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int i, n;
    char *sports[10];
    char str[100];

    printf("enter the number of sports: ");
    scanf("%d", n);
    for (int i = 0; i < n; i++)
    {
        printf("enter the name of the sports");
        scanf("%s", str);
        sports[i] = (char *)malloc(strlen(str) * sizeof(char));
        strcpy(sports[i], str);
    }
    printf("Given list is");
    for (int i = 0; i < n; i++)
    {
        printf("%s", sports[i]);
    }
    for (int i = 0; i < n; i++)
    {
        free(sports[i]);
    }

    return 0;
}
