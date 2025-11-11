#include<stdio.h>

void pointer_to_array(int m,int n,int (*arr)[n])
{
    printf("Pointer to array : \n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void array_of_pointers(char *strarr[])
{
    printf("Array of pointers : \n");
    for(int i = 0; i < 3; i++)
    {
        printf("%s  ",strarr[i]);
        printf("\n");
    }
}

int main()
{
    int m,n;
    printf("Enter the size of array : ");
    scanf("%d %d",&m,&n);
    
    int arr[m][n];
    printf("Enter the elements of array : \n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\n");

    pointer_to_array(m,n,arr);

    char *strarr[] = {"Hello" , "Akash" , "How are you ?"};

    array_of_pointers(strarr);

    return 0;
}