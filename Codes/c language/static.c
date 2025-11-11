#include<stdio.h>

int static_fun()
{
    static int num = 0;
    num++;
    return num;
}

int main()
{
    for(int i = 0; i < 5; i++)
    {
        printf("%d\n",static_fun());
    }

    return 0;
}