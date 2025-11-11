#include <stdio.h>
#include <math.h>

#define e 2.78
#define f(x) pow(e,-pow(x,2))

int main()
{
    float upperlimit=1, lowerlimit=0, interval=100000;
    float dx, sum = 0;
    dx = (upperlimit - lowerlimit) / interval;

    for (float i = lowerlimit; i <= upperlimit; i += dx)
    {
        sum += f(i) * dx;
    }
    printf("Answer of the integration= %f", sum);

    return 0;
}