#include <bits/stdc++.h>
using namespace std;

int j = 0;

void divisor(int x)
{
    int n;
    cin >> n;
    int count = 0;
    int sqrt_n = sqrt(n);
    for (int i = 1; i <= sqrt_n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if (i * i != n) 
            { 
                count++; 
            }
        }
    }
    cout << count << endl;

    if (j < x - 1) 
    {
        j++;
        divisor(x);
    }
}

int main()
{
    int x;
    cin >> x;
    divisor(x);

    return 0;
}
