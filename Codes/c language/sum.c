#include<stdio.h>
int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);

    int sum = 0;
    for (n; n>0; n = n/10)
    {
        sum = sum + n%10;
    }
    printf("%d",sum);
    
return 0;
}