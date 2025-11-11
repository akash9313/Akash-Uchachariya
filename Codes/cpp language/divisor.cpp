#include <iostream>
using namespace std;

int j = 0;

void divisor(int x)
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
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
