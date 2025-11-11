#include<stdio.h>

int main()
{
    int x,y,z;
    printf("Enter the size of array : ");
    scanf("%d %d %d",&x,&y,&z);

    int arr[x][y][z];
    printf("Enter the elements of array : \n");
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            for(int k = 0; k < z; k++)
            {
                scanf("%d",&arr[i][j][k]);
            }
        }
    }

    printf("Entered the elements of array are : \n");
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            for(int k = 0; k < z; k++)
            {
                printf("%d  ",arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}