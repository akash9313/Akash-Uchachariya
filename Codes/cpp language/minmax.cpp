#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the numbers in array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int smallest = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < smallest)
        {
        smallest = arr[i];
        }
    }
    cout<<"Smallest number is : "<<smallest<<endl;

    int largest = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > largest)
        {
        largest = arr[i];
        }
    }
    cout<<"Largest number is : "<<largest;

    return 0;
}