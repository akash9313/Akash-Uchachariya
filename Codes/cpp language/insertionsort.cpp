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
    for(int i = 1; i < n; i++)
    {
       int current = arr[i];
       int j = i - 1;
       while(arr[j]>current && j>=0){
        arr[j + 1] = arr[j];
        j--;
       }
       arr[j + 1] = current;
       count++;
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
