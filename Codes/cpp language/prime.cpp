#include<iostream>

using namespace std;

void primefactor(int n)
{
    for (int i = 2; i <= n; i++)
    {
        for(i ; n % i == 0; n = n / i)
        {
            cout<<i<<endl;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;

    primefactor(n);

    return 0;

}
