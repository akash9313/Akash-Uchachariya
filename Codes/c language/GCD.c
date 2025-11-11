#include<stdio.h>

int GCD(int a, int b)
{
    int min,c;
    
    for(int j = 1; j <=a; j++)
    {
        if(a%j == 0 || b%j == 0)
        {
            c=c*j;
        }
    }
return c;  
}


int main()
{
int a,b;
printf("Enter a and b : ");
scanf("%d %d",&a,&b);

printf("%d\n", GCD(a,b));

return 0;
}