#include<stdio.h>

int main()
{
    int arr[5], i;
    printf("Enter five numbers : \n");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (i = 0; i < 5 ; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("maximum number is %d\n", max);

    int min = arr[0];
    for (i = 0; i < 5 ; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("minimum number is %d\n", min);

    return 0;
}
