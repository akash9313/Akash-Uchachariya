#include<stdio.h>
int main()
{
    int m,n;
    printf("Enter rows and cols: ");
    scanf("%d %d",&n,&m);
    int arr[n][m];
    printf("Enter elements of matrix: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
         }
    }
    printf("transpose: \n");
    int transpose[n][m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",transpose[j][i]);
        }
        printf("\n");
    }
    //90.degree .
    printf("\n");
    int r1,r2,dummy;
    r1=0,r2=n-1;
    for(int i=0;i<n;i++)
    {
        int temp=arr[r1][i];
        arr[r1][i]=arr[r2][i];
        arr[r2][i]=temp;
        for(int j=0;j<m;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    


return 0;
}