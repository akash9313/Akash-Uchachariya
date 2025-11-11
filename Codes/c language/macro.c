#include<stdio.h>

#define pi 3.14

int main()
{
    float radius;
    printf("Enter the radius : ");
    scanf("%f",&radius);

    float area = pi*radius*radius;
    printf("Area of circle is %0.2f of radius %0.2f",area,radius);

    return 0;
}