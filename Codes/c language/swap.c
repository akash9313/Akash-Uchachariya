#include<stdio.h>

void swap(int *a,int*b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;

    printf("Swaped values are : %d and %d",*a,*b);
}

int main()
{
    int a,b;
    printf("Enter a and b : ");
    scanf("%d %d",&a,&b);

    swap(&a,&b);

    return 0;
}