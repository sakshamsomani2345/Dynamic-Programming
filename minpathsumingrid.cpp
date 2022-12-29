#include <bits/stdc++.h>
using namespace std;
int uniquepaths(vector<vector<int>> unique, int m, int n)
{
    if (m == 0 && n == 0)
    {
        return unique[0][0];
    }
    if (n < 0 || m < 0)
    {
        return 1e9;
    }
    int path1 = unique[m][n] + uniquepaths(unique, m - 1, n);
    int path2 = unique[m][n] + uniquepaths(unique, m, n - 1);
    return min(path1, path2);
}
int memo(vector<vector<int>> x, vector<vector<int>> dp, int m, int n)
{
    if (m == 0 && n == 0)
    {
        return x[0][0];
    }
    if (n < 0 || m < 0)
    {
        return 1e9;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int path1 = x[m][n] + memo(x, dp, m - 1, n);
    int path2 = x[m][n] + memo(x, dp, m, n - 1);
    return min(path1, path2);
}
int dpe(vector<vector<int>> x, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    return memo(x, dp, m, n);
}
int tabular(vector<vector<int>> x, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1,0));
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = x[i][j];
            }else{
            int path1 = x[i][j] ;
            if (i >= 1)
            {
                 path1 +=dp[i - 1][j];
            }else{
                path1+=1e9;
            }
            int path2 = x[i][j];
            if (j >= 1)
            {
                 path2 +=dp[i][j-1];
            }else{
                path2+=1e9;
            }
            dp[i][j]=min(path1,path2);
            cout<<dp[i][j]<<endl;}
        }
    }
    return dp[m][n];
}
int optimised(int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> cur(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                cur[j] = 1;
            }
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                {
                    up = prev[j];
                }
                if (j > 0)
                {
                    left = cur[j - 1];
                }
                cur[j] = up + left;
            }
        }
        prev = cur;
    }
    return prev[n - 1];
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dp[i][j];
        }
    }
   

    cout << tabular(dp, m - 1, n - 1);
}