#include <bits/stdc++.h>
using namespace std;
int mcm(int i, int j, vector<int> arr)
{
    if (i > j)
    {
        return 0;
    }
    int mini = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        int steps = arr[j + 1] - arr[i - 1] + mcm(i, k - 1, arr) + mcm(k + 1, j, arr);
        mini = min(mini, steps);
    }
    return mini;
}
// TC=>EXPONENTIAL
int tabular(vector<int> arr, int n, int cost)
{
     arr.push_back(n);
    arr.insert(arr.begin(), 0);
    sort(arr.begin(), arr.end());
    return mcm(1, cost, arr);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
            {
                continue;
            }
            int mini = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                int steps = arr[j + 1] - arr[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n];
}
int mincost(vector<int> arr, int n, int cost)
{
    arr.push_back(n);
    arr.insert(arr.begin(), 0);
    sort(arr.begin(), arr.end());
    return mcm(1, cost, arr);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;
    cout << tabular(arr, x, n);
}