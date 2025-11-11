#include <stdio.h>

int isPrime(int n) 
{
    if (n <= 1) 
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            return 0;
        }
    }
    return 1;
}

int main() 
{
    int n;
    printf("Enter an odd integer greater than 5 : ");
    scanf("%d", &n);

    if (n % 2 == 0 || n <= 5) 
    {
        printf("Invalid number entered\n");
        return 1;
    }
    else
    {
        for (int i = 2; i <= n; i++) 
        {
            if (isPrime(i)) 
            {
                for (int j = i; j <= n; j++) 
                {
                    if (isPrime(j)) 
                    {
                        for (int k = j; k <= n; k++) 
                        {
                            if (isPrime(k) && (i + j + k == n)) 
                            {
                                printf("%d + %d + %d = %d\n", k, i, j, n);
                                 
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
