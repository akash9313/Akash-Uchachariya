#include <bits/stdc++.h>
using namespace std;

void mergesortjoin(int arr[], int lower, int middle, int higher)
{
    int leftarr[middle - lower + 1];
    int rightarr[higher - middle];

    for (int i = 0; i < middle - lower; i++)
    {
        leftarr[i] = arr[lower + i];
    }

    for (int i = 0; i < higher - middle; i++)
    {
        rightarr[i] = arr[middle + i];
    }

    int i = 0, j = 0, k = 0;
    while (k < middle && j < higher)
    {
        if (leftarr[k] < rightarr[j])
        {
            arr[lower + i] = leftarr[k];
            k++;
            i++;
        }
        else
        {
            arr[lower + i] = rightarr[k];
            j++;
            i++;
        }
    }

    while (k < middle)
    {
        arr[lower + i] = leftarr[k];
        k++;
        i++;
    }

    while (j < higher)
    {
        arr[lower + i] = rightarr[j];
        j++;
        i++;
    }
}

void mergeSortdivide(int arr[], int lower, int higher)
{
    int middle = lower + (higher - lower) / 2;
    mergeSortdivide(arr, lower, middle);
    mergeSortdivide(arr, middle + 1, higher);

    mergesortjoin(arr, lower, middle, higher);
}

int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the element of array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSortdivide(arr, 0, n - 1)

        for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}