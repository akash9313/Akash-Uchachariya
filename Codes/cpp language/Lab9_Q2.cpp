#include <iostream>
using namespace std;

class FindMisNum
{
public:
    int findMissing(int arr[], int n)
    {
        int total = n * (n + 1) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        return total - sum;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements in array : ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " distinct numbers in the range [0, " << n << "]: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    FindMisNum obj;
    cout << "Missing number: " << obj.findMissing(arr, n) << endl;

    return 0;
}
