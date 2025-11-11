#include <stdio.h>

int LCM_(int m, int n)
{
    static int x = 0;
    x = x + n;

    if ((x % m == 0) && (x % n == 0)) 
    {
        return x;
    } 
    else 
    {
        return LCM_(m, n);
    }
}

int main() 
{
    int m,n,LCM;
    printf("Enter two numbers : ");
    scanf("%d %d", &m, &n);
    
    LCM = LCM_(m,n);

    printf("LCM of %d and %d = %d\n", m,n,LCM);

    return 0;
}


