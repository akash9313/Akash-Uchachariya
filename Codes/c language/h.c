#include<stdio.h>

int main()
{
    for (int i = 0; i <= 9; i++)
    {
        auto int x = 10;  // 'auto' is optional for local variables
        printf("%d", x);
    }
    
    return 0;
}