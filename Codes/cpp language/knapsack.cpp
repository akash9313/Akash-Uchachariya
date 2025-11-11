#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int n, int W)
{
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int n;
    cout << "Enter number of items : ";
    cin >> n;

    int wt[n], val[n];
    cout << "Enter weights of items : ";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << "Enter values of items : ";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    int W;
    cout << "Enter capacity of knapsack : ";
    cin >> W;

    cout << "Maximum value in knapsack is : " << knapsack(wt, val, n, W);

    return 0;
}
