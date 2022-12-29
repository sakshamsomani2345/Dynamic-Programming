#include <bits/stdc++.h>
using namespace std;
int lis(int *arr, int n, int prev, int length)
{
    if (n == length)
    {
        return 0;
    }
    int nottake = lis(arr, n + 1, prev, length);
    int take = INT_MIN;
    if (prev == -1 || arr[n] > arr[prev])
    {
        take = 1 + lis(arr, n + 1, n, length);
    }
    return max(take, nottake);
}
int memo(vector<vector<int>> dp, int *arr, int n, int prev, int length)
{
    if (n == length)
    {
        return 0;
    }
    if (dp[n][prev + 1] != -1)
    {
        return dp[n][prev + 1];
    }
    int nottake = memo(dp, arr, n + 1, prev, length);
    int take = INT_MIN;
    if (prev == -1 || arr[n] > arr[prev])
    {
        take = 1 + memo(dp, arr, n + 1, n, length);
    }
    return dp[n][prev + 1] = max(take, nottake);
}
int dpe(int *arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return memo(dp, arr, 0, -1, n);
}
int tabular(int *arr, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int len = dp[i + 1][j + 1];
            if (j == -1 || arr[i] > arr[j])
            {
                len = max(len, 1 + dp[i + 1][i + 1]);
            }
            dp[i][j + 1] = len;
        }
    }
    return dp[0][0];
}
int otherway(int *arr, int n)
{
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
vector<int> printlcs(int *arr, int n)
{
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            last = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[last]);
    while (hash[last] != last)
    {
        last = hash[last];
        temp.push_back(arr[last]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
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

    // cout << tabular(arr, n);
    vector<int> x = printlcs(arr, n);
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i];
    }
}