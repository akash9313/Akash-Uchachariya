#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dec;
    cout << "Enter the decimal : ";
    cin >> dec;

    int result;
    int bi_num = 0;
    for (int i = 0; i <= dec; i++)
    {
        result = dec % 2;
        bi_num = bi_num + result * pow(10, i);
        dec = dec / 2;
        if (dec == 0)
        {
            break;
        }
    }

    cout << bi_num;

    return 0;
}
