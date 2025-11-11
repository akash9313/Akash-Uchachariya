#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int count = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i) 
        {
            swap(arr[i], arr[min]);
            count++;
        }
    }

    cout<<"After selection sort: ";
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i] << " ";
    }
    cout<<"\nTotal swaps: ";
    cout<<count << endl;

    return 0;
}
