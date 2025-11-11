#include<stdio.h>

int main()
{
    int start,end;
    printf("enter starting ascii value : \n");
    scanf("%d",&start);
    printf("enter ending ascii value : \n");
    scanf("%d",&end);
    printf("spatial characters are : \n");

    for (int i = start; i <= end; i++)
    {
        printf("%c \t ",i);
        printf("%d\n",i);
    }

    return 0;
}