#include <bits/stdc++.h>
using namespace std;
int stockprofit(int *arr, int n, bool buy, int index, int count)
{
    if (count == 0)
    {
        return 0;
    }
    if (n == index)
    {
        return 0;
    }

    int profit = 0;
    if (buy)
    {
        profit = max(-arr[n] + stockprofit(arr, n + 1, false, index, count), stockprofit(arr, n + 1, true, index, count));
    }
    else
    {
        profit = max(arr[n] + stockprofit(arr, n + 1, true, index, count - 1), stockprofit(arr, n + 1, false, index, count));
    }
    return profit;
}
int memo(int *arr, int n, int buy, int index, vector<vector<vector<int>>> dp,int count)
{
      if (count == 0)
    {
        return 0;
    }
    if (n == index)
    {
        return 0;
    }
    if (dp[n][buy][count]!= -1)
    {
        return dp[n][buy][count];
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-arr[n] + memo(arr, n + 1, false, index, dp,count), memo(arr, n + 1, true, index, dp,count));
    }
    else
    {
        profit = max(arr[n] + memo(arr, n + 1, true, index, dp,count-1), memo(arr, n + 1, false, index, dp,count));
    }
    return dp[n][buy][count] = profit;
}
int dp(int *x, int n)
{
    vector<vector<vector<int>>> array(n, vector<vector<int>>(2,vector<int>(3,-1)));
    return memo(x, 0, true, n, array,2);
}
int tabulation(int *arr, int n)
{
   vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));
//    for (int i = 0; i < n-1; i++)
//    {
//     for (int j = 0; j < 1; j++)
//     {
//         dp[i][j][0]=0;
//     }
    
//    }
//    for (int i = 0; i < 1; i++)
//    {
//     for (int j = 0; j < 2; j++)
//     {
//         dp[n][i][j]=0;
//     }
    
//    }
   
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 1; k < 3; k++)
            {
                if(j==1){
                    dp[i][j][k]=max(-arr[i]+dp[i+1][0][k],dp[i+1][1][k]);
                }else{
                    dp[i][j][k]=max(arr[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                }
            }
            
           
        }
    }
    return dp[0][1][2];;
}
int optimised(int *arr, int n)
{
    vector<int> ahead(2, 0);
    vector<int> curr(2, 0);

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
                profit = max(arr[i] + ahead[1], ahead[0]);
            }
            curr[j] = profit;
        }
        ahead = curr;
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
    cout << tabulation(arr, n);
}