#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int* A = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int largest = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > largest)
        {
            largest = A[i];
        }
    }
    cout << largest << " ";

    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] < A[i + 1])
        {
            cout << A[i] << " ";
        }
        else
        {
            cout << A[i + 1] << " ";
        }
    }
    return 0;
}