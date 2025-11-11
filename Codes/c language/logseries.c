#include<stdio.h>

float power(float a,float b)
{
    float product=1;
    for(int j=1;j<=b;j++){
        product=product*a;
    }
    return product;
}
int main()

{
    printf("enter a number:");
    float n;
    scanf("%f",&n);
    
    float sum=0;
    for(float i=1;i<=7;i++){
        printf("  %0.0fx^%0.0f/%0.0f\t",power(-1,i+1),i,i);
        sum=sum+power(-1,i+1)*((power(n,i)/i));
    }
    printf("\n");
    printf("sum of the series is:%f",sum);
}