#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int count = 0;
    int i = 0, j = 0, k = left;

    for (; i < n1 && j < n2; )
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
            count += (n1 - i);
        }
    }

    for (; i < n1; i++)
    {
        arr[k++] = leftArr[i];
    }

    for (; j < n2; j++)
    {
        arr[k++] = rightArr[j];
    }

    return count;
}

int mergeSortAndCount(int arr[], int left, int right)
{
    int count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        count += mergeSortAndCount(arr, left, mid);
        count += mergeSortAndCount(arr, mid + 1, right);
        count += mergeAndCount(arr, left, mid, right);
    }
    return count;
}

int countInversions(int arr[], int n)
{
    return mergeSortAndCount(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countInversions(arr, n);
    cout << "Number of inversions are: " << result << endl;

    return 0;
}