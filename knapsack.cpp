#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int *weight, int *value, int cap)
{
    if (n == 0)
    {
        return 0;
    }
    if (cap == 0)
    {
        return 0;
    }
    int x = INT_MIN;
    if (cap >= weight[n])
    {
        x = value[n] + knapsack(n - 1, weight, value, cap - weight[n]);
    }
    int y = knapsack(n - 1, weight, value, cap);
    return max(x, y);
}
int memo(int *wt, int *val, int n, int cap, vector<vector<int>> dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (cap == 0)
    {
        return 0;
    }
    if (dp[n][cap] != -1)
    {
        return dp[n][cap];
    }
    int x = INT_MIN;
    if (cap >= wt[n])
    {
        x = val[n] + memo(wt, val, n - 1, cap - wt[n], dp);
    }
    int y = memo(wt, val, n - 1, cap, dp);
    dp[n][cap] = max(x, y);
    return dp[n][cap];
}
int dpe(int *wt, int *val, int n, int cap)
{
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));
    return memo(wt, val, n, cap, dp);
}
int tabular(int *wt, int *val, int n, int cap)
{
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < cap + 1; j++)
        {
            dp[0][j] = 0;
            dp[i][0] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < cap; j++)
        {
            int x = INT_MIN;
            if (j >= wt[i])
            {
                x = val[i] +dp[i-1][j-wt[i]];
            }
            int y =dp[i-1][j];
            dp[n][cap] = max(x, y);
        }
    }
    return dp[n][cap];
}
int main()
{
    int n;
    cin >> n;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    int x;
    cin >> x;
    cout << tabular(wt, val, n - 1, x);
}