#include<stdio.h>

int main()
{
    int n,p = 0;
    printf("enter n : ");
    scanf("%d",&n);
     for (int i = 1; i <=n; i++)
     {
        if(n%i == 0)
        {
            p++;
        }
     }
        if (p>2)
        {
            printf("entered number is not prime");
        }
        else{
            printf("entered number is prime");
        }
        return 0;
     
}