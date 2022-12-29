#include <bits/stdc++.h>
using namespace std;
int uniquepaths(int m, int n)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (n < 0 || m < 0)
    {
        return 0;
    }
    int path1 = uniquepaths(m - 1, n);
    int path2 = uniquepaths(m, n - 1);
    return path1 + path2;
}
int memo(vector<vector<int>> dp, int m, int n)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (n < 0 || m < 0)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    dp[m][n] = memo(dp, m - 1, n) + memo(dp, m, n - 1);
    return dp[m][n];
}
int dp(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    return memo(dp, m, n);
}
int tabular(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            if (i >= 1)
            {
                dp[i][j] += dp[i - 1][j];
            }
            if (j >= 1)
            {
                dp[i][j] += dp[i][j - 1];
            }
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
    cout << tabular(m-1, n-1);
}