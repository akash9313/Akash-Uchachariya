#include <stdio.h>
int GCD(int num1, int num2)
{
    while (num1 != num2)
    {
        // if num1 is greater than num2, returns the num1.
        if (num1 > num2)
        {
            num1 = num1 - num2;
        }

        else
        {
            num2 = num2 - num1;
        }
    }
    return num1;
}
int main()
{
    int n = 8; // we will be printing it till n+1 th column
    printf("Print rational numbers of given sequence till %i, %i\n\n", n, n);
    int sum = 2;
    int changeside = 0;
    n++;
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        int deno = 1;
        if (changeside == 1)
        {
            deno = i;
            num = 1;
        }
        if (num + deno <= n && GCD(num, deno) == 1)
        {
            printf("%i/%i ", num, deno);
        }
        if (i == 1)
        {
            sum++;
            continue;
        }
        while (num + deno == sum && sum <= n)
        {
            if (num - 1 == 0 && changeside == 0)
            {
                changeside = 1;
                break;
            }
            if (deno - 1 == 0 && changeside == 1)
            {
                changeside = 0;
                break;
            }
            if (changeside == 0)
            {
                deno++;
                num--;
            }
            else
            {
                num++;
                deno--;
            }
            GCD(num,deno)==1?printf("%i/%i ", num, deno):num;
        }
        sum++;
    }
}