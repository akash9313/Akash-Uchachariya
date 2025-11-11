#include<stdio.h>

int main()
{
    int arr[6];

    printf("Enter numbers : \n");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Stored integers are  : \n");
    
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}