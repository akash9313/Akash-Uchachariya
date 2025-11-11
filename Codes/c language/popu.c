#include<stdio.h>
int main()
{
    int year = 10;
   
    int pop = 100000;
    float fpop = pop;
    for (int i = 1; i <=year; i++)
    {
        fpop = fpop*0.1 + fpop;
        printf("Final population is : %0.2f and year %d\n",fpop,i);
    }
    
return 0;
}