#include<stdio.h>

int nfactorial(int n)
{
    int nfact = 1;
    for (int i = 2; i <= n; i++)
    {
        nfact = nfact*i;
    }
    return nfact;
}

int nrfactorial(int n, int r)
{
    int nrfact = 1;
    for (int i = 2; i <= n-r; i++)
    {
        nrfact = nrfact*i;
    }
    return nrfact;
}

int main()
{
    int n,r;
    printf("Enter n & r : \n");
    scanf("%d",&n);
    scanf("%d",&r);

    int nfact = nfactorial(n);
    int nrfact = nrfactorial(n,r);

    int combination = nfact/nrfact;
    printf("Combination is : %d",combination);
    return 0;
}