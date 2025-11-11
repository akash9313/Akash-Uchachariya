#include <stdio.h>

int prime(int p) 
{
    if (p <= 1)
    { 
    return 0;
    }
    
    for (int i = 2; i * i <= p; i++) 
    {
        if (p % i == 0) 
        {
            return 0; 
        }
    }
    return 1; 
}

void pair(int n) 
{
    int count = 0;
    for (int j = 2; count < n && j < 2000; j++) 
    {
        if (prime(j) && prime(j + 2)) 
        {
            printf(("%d,%d\n"), j, j + 2);
            count++;
        }
    }
}

int main() 
{
    printf("Enter number: ");
    int n;
    scanf("%d", &n);
    pair(n);

    return 0;
}
