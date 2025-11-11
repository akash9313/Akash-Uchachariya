#include<stdio.h>

int main()
{
    int n;
    printf("Enter n : \n");
    scanf("%d",&n);

    
    double fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;  
    }

    printf("factorial is : \n%lf",fact);

    return 0;
}