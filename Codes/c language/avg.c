#include<stdio.h>

int main()
{
    int n;
    printf("ENter size of array : ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter integers in array : ");
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    printf("Average of entered numbers is : %0.2f",sum/n);

    return 0;
}