#include<stdio.h>
#include<math.h>

int fact(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

void sincosseries(float x, int k)
{
    float f = 0.0;
    for (int i = 0; i <= k; i++) 
    {
        f = f + (pow(-1, i) * pow(x, 2 * i + 1)) / fact(2 * i + 1);
    }

    float g = 0.0;
    for (int i = 0; i <= k; i++) 
    {
        g = g + pow(x, 2 * i) / fact(2 * i);
    }
    printf("The sum of sin and cos series is: %f and %f\n", f, g);
}

int main()
{
    float x;
    printf("Enter the value of x: ");
    scanf("%f", &x);

    int k;
    printf("Enter the value of k (limit): ");
    scanf("%d", &k);

    sincosseries(x, k);
    
    return 0;
}
