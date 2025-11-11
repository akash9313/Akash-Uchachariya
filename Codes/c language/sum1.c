#include<stdio.h>

int Without_Recursion(int n)
{
    int sum = 0;
    for (n; n > 0; n = n/10)
    {
        sum = sum + n%10;
    }
    return sum; 
}

int With_Recursion(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return n%10 + With_Recursion(n/10);
    }
}

int main()
{
    int n;
    printf("Enter n : "); 
    scanf("%d",&n);

    printf("Sum without using recursion : %d\n",Without_Recursion(n));

    printf("Sum with using recursion : %d\n",With_Recursion(n));


    return 0;
}