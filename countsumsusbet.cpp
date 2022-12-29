#include <bits/stdc++.h>
using namespace std;
int subsetsum(int n, int k, int *arr)
{
    if (k == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return arr[0] == k;
    }
    int x = subsetsum(n - 1, k, arr);

    int y = 0;
    if (k >= arr[n])
    {
        y = subsetsum(n - 1, k - arr[n], arr);
    }
    return x + y;
}
int memo(vector<vector<int>> dp, int n, int k, int *arr)
{
    if (k == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return arr[0] == k;
    }
    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }
    int x = memo(dp, n - 1, k, arr);
    int y = false;
    if (k >= arr[n])
    {
        y = memo(dp, n - 1, k - arr[n], arr);
    }
    dp[n][k] = x + y;
    return dp[n][k];
}
int tabular(int *arr, int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int j = 0; j < n + 1; j++)
    {
        dp[j][0] = 1;
    }
    if (arr[0] <= k)
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            int x = dp[i - 1][j];
            int y = 0;
            if (j >= arr[i])
            {
                 y = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = x + y;
        }
    }
    return dp[n][k];
}
int dpe(int *arr, int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return memo(dp, n, k, arr);
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

    int k;
    cin >> k;
    cout << tabular(arr, n - 1, k);
    // cout<<subsetsum(n,k,arr);
}