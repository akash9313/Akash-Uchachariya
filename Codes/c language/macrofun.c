#include<stdio.h>

#define pi 3.14
#define areaofcircle(r) (pi*r*r)

int main()
{
    float radius;
    printf("Enter the radius : ");
    scanf("%f",&radius);

    printf("The area of circle is %0.23f",areaofcircle(radius));

    return 0;
}