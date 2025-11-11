#include<iostream>

using namespace std;

int main()
{
    int m,n;
    cout<<"Enter the row : ";
    cin>>m;

    cout<<"Enter the coloumn : ";
    cin>>n;

    int matrix[m][n];
    cout<<"Enter the numbers in matrix : \n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
        
    }
    //Transpose of matrix
    int matrix1[n][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix1[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<matrix1[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
     return 0;
}