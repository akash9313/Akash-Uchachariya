#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int x;
    cin >> x;

    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    bool triplet=false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (A[i] + A[j] + A[k] == x && i != j && j != k && i != k)
                {
                    cout << A[i] << " " << A[j] << " " << A[k] << endl;
                    triplet = true;
                }
            }
        }
    }
}