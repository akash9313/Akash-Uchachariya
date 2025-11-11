#include<stdio.h>

int main()
{
    int n,m;
    printf("Enter n : ");
    scanf("%d",&n);

    for (int i = 1; i <= n; ++i)
    {
        for (int m = 1; m <= n - i; ++m)
        {
            printf("  ");
        }
        for (int j = 1; j <= 2 * i - 1; ++j)
        {
            printf("* ");
        }
        
        printf("\n");
    }

    return 0;
    
}
