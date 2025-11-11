#include<stdio.h>

void largestN(int arr[]);

int main()
{
    int arr[3];
    printf("Enter three numbers = ");
    scanf("%d", &arr[0]);
    scanf("%d", &arr[1]);
    scanf("%d", &arr[2]);

    largestN(arr);
    printf("arr[0] = %d, arr[1] = %d, arr[2] = %d", arr[0], arr[1], arr[2]);
    return 0;
}

void largestN(int arr[])
{
    if(arr[0] > arr[1] && arr[0] > arr[2])
    {
        printf("Largest number is : %d \n", arr[0]);
    }
    else if (arr[1] > arr[0] && arr[1] > arr[2])
    {
        printf("Largest number is : %d \n", arr[1]);
    }
    else if (arr[2] > arr[0] && arr[2] > arr[1])
    {
        printf("Largest number is : %d \n", arr[2]);
    }
    else 
    {
        printf("All numbers are same : ");
    }
    
}
