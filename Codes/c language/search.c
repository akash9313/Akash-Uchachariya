#include<stdio.h>

void search_element(int *size, int arr[],int *element)
{
    int i;
    for(i = 0; i < *size; i++)
    {
        if(*element == arr[i])
        {
            printf("Element exist in array\n");
            break;
        }
    }

    if(*element != arr[i])
    {
        printf("Element does not exist in array\n");
    }

}

int main()
{
    int size;
    printf("Enter size : ");
    scanf("%d",&size);

    int arr[size];
    printf("Enter numbers in arr : ");

    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }

    int element;
    printf("Enter element : ");
    scanf("%d",&element);

    search_element(&size,arr,&element);

    return 0;
}