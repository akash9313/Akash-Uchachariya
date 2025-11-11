#include<stdio.h>

int main()
{
    int size;
    printf("Enter size : ");
    scanf("%d",&size);

    int arr[size];
    printf("Enter numbers : ");

    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }   
    }

    printf("After bubble sort\n");

    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    return 0;
}