#include<stdio.h>
int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);

    int limit;
    printf("Enter the limit : ");
    scanf("%d",&limit);

    float sum = 0;
    for (int  i = 1; i <= limit; i++)
    {
        sum = sum + 1.0/i;
        if(sum > n)
        {
            printf("k is %d",i);
            break;
        }
    }
    

return 0;
}