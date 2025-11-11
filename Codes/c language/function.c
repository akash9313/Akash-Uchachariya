#include<stdio.h>

int main()
{
    int n;
    printf(("Enter number up to which you want to store a function : "));
    scanf("%d",&n);

    int f[n];
    for (int i = 0; i < n; i++)
    {
        f[i] = i + 1;
    }

    printf("For function f:{1,2,3,4,5} --> N\n");

    for (int i = 0; i < n; i++)
    {
        printf("f(%d) = %d\n",i + 1,f[i]);
    }
    
    return 0;
}