#include<stdio.h>

void without_pointer(int m,int n,int arr[m][n])
{
    printf("Array without pointer : \n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void with_pointer(int m,int n,int (*arr)[n])
{
    printf("Array with pointer : \n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int m,n;
    printf("Enter the size of array : ");
    scanf("%d %d",&m,&n);

    int arr[m][n];
    printf("Enter elements in array : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");
    
    with_pointer(m,n,arr);
    without_pointer(m,n,arr);

    return 0;
}