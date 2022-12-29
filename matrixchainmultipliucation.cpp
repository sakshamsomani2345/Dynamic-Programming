#include <bits/stdc++.h>
using namespace std;
int mcm(int *arr, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + mcm(arr, i, k) + mcm(arr, k + 1, j);
        mini = min(mini, steps);
    }
    return mini;
}
// TC=>EXPONENTIAL
int memo(int i, int j, int *arr, vector<vector<int>> dp)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + memo(i, k, arr, dp) + memo(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }
    dp[i][j] = mini;
    return dp[i][j];
}
int dp(int *arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return memo(1, n - 1, arr, dp);
}
int tabular(int *arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 1; i < n; i++)
    {
        dp[i][i]=0;    }
    
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] +dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << tabular(arr, n);
}