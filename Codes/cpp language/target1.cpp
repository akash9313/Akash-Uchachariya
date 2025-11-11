#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[9] = {1,2,1,2,3,4,5,3,5};

    int i, j;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if(arr[i] == arr[j])
            {
                arr[i] = arr[j] = -1;
            }
        }
    }

    for(int k = 0; k < 9; k++)
    {
        if(arr[k] > 0)
        {
            cout<< arr[k] <<endl;
        }
    }
    

    return 0;
}
