#include<bits/stdc++.h>
using namespace std;

int maxindex(int arr[], int size)
{
    int max = INT_MIN;
    int maxindex = -1;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            maxindex = i;
        }
    }
    return maxindex;
}

int main()
{
    int size;
    cout<<"Enter the size of arr : ";
    cin>>size;

    int arr[size];
    cout<<"Enter numbers in arr : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    int maxnum = maxindex(arr,size);
    arr[maxnum] = -1;

    int secondmaxnum = maxindex(arr,size);

    cout<<"Second last max number is : "<<arr[secondmaxnum];

    return 0;
}