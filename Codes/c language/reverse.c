#include<stdio.h>

int main()
{
    int arr[5];
    printf("Enter five numbers : \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("reverse numbers are : \n");

    for (int i = 4; i >= 0; i--)
    {   
        printf("%d\t",arr[i]);
    }
    
    return 0;
}