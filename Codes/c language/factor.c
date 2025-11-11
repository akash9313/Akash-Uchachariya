#include<stdio.h>

int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    if(n == 0)
    {
        printf("You can not enter 0 \n");
    }

    printf("Factors are : \n");

    for (int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            printf("%d\n",i);
        }
    }

    return 0;

}