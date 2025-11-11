#include<stdio.h>

#define n 5

int main()
{
    printf("Number is 5\n");
    #if n % 2 == 0
        printf("Entered number is even");

    #elif n % 2 != 0
        printf("Entered number is odd");

    #endif

    return 0;
}
