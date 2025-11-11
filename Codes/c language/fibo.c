#include<stdio.h>

int fib(int n)
{
    int a,b;
    if(n < 2)
    {
        return 1;
    }

    return fib(n-1) + fib(n-2);

}

int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    
    printf("Fibonacci series is : \n");
    for(int i = 0; i <= n; i++)
    {
        printf("%d  ",fib(i));
    }

    return 0;
}