#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the total number : ";
    cin>>n;

    int num[n];
    cout<<"Enter the numbers : ";
    for(int i = 0; i < n; i++)
    {
        cin>>num[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (num[j] < num[i])
            {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            // }
            // if(num[i] == num[j])
            // {
            //     num[j] = NULL;
            //     num[i] = num[i-1];
            }
        }
        
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (num[j] == num[i])
            {
                count++;
            }
        }
    }
    //cout<<count<<endl;

    int sortnum[n - count];

    for (int i = 0; i < n; i++)
    {
        cout<<num[i];
    }
    
    return 0;
}