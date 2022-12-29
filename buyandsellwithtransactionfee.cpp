#include <bits/stdc++.h>
using namespace std;
int stockprofit(int *arr, int n, bool buy, int index,int fee)
{
    if (n == index)
    {
        return 0;
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-arr[n]-fee + stockprofit(arr, n + 1, false, index,fee), stockprofit(arr, n + 1, true, index,fee));
    }
    else
    {
        profit = max(arr[n] + stockprofit(arr, n + 1, true, index,fee), stockprofit(arr, n + 1, false, index,fee));
    }
    return profit;
}
int memo(int *arr, int n, int buy, int index, vector<vector<int>> dp,int fee)
{
    if (n == index)
    {
        return 0;
    }
    if (dp[n][buy] != -1)
    {
        return dp[n][buy];
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-arr[n] -fee+ memo(arr, n + 1, false, index, dp,fee), memo(arr, n + 1, true, index, dp,fee));
    }
    else
    {
        profit = max(arr[n] + memo(arr, n + 1, true, index, dp,fee), memo(arr, n + 1, false, index, dp,fee));
    }
    return dp[n][buy] = profit;
}
int dp(int *x, int n,int fee)
{
    vector<vector<int>> array(n, vector<int>(2, -1));
    return memo(x, 0, true, n, array,fee);
}
int tabulation(int *arr, int n,int fee)
{
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            int profit = 0;
            if (j)
            {
                profit = max(-arr[i]-fee + dp[i+1][0], dp[i+1][1]);
            }
            else
            {
                 profit = max(arr[i]+ dp[i+1][1], dp[i+1][0]);
            }
            dp[i][j]=profit;
        }
    }
    return dp[0][1];
}
int optimised(int *arr, int n)
{
    vector<int> ahead(2,0);
    vector<int> curr(2,0);

    ahead[0] = ahead[1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            int profit = 0;
            if (j)
            {
                profit = max(-arr[i] + ahead[0], ahead[1]);
            }
            else
            {
                 profit = max(arr[i]+ ahead[1], ahead[0]);
            }
            curr[j]=profit;
        }
        ahead=curr;
    }
    return ahead[1];
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
    int fee;
    cin>>fee;
    cout << tabulation(arr, n,fee);
}