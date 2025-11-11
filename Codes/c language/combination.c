#include<stdio.h>

int factorial(int n)
{
    int nfact = 1;
    for (int i = 2; i <= n; i++)
    {
        nfact = nfact*i;
    }
    return nfact;
}

int main()
{
    int n,r;
    printf("Enter n & r : \n");
    scanf("%d",&n);
    scanf("%d",&r);

    int ncr = factorial(n)/(factorial(r)*factorial(n-r));

    printf("Combination is : %d",ncr);
    return 0;
}

