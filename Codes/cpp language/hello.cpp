#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the n : ";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        for (int j = 0; j < n; j++)
        {
            num = num + 1;
            cout<<"  "<<num;
        }
        cout<<endl;
    }

    return 0; 
}